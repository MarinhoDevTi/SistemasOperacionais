#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TAMANHO 10

/* Estrutura para passagem de dados aos threads classificadores */
typedef struct {
    int *array;
    int inicio;
    int fim;
} parameters;

/* Função de comparação */
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/* Função que cada thread classificadora executará */
void *classificar(void *param) {
    parameters *p = (parameters *)param;
    qsort(p->array + p->inicio, p->fim - p->inicio + 1, sizeof(int), comparar);
    pthread_exit(NULL);
}

/* Função que o thread de mesclagem executará */
void *mesclar(void *param) {
    parameters *p = (parameters *)param;
    int meio = (p->fim + p->inicio) / 2;
    int *temp = (int *)malloc((p->fim - p->inicio + 1) * sizeof(int));

    int i = p->inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= p->fim) {
        if (p->array[i] < p->array[j]) {
            temp[k++] = p->array[i++];
        } else {
            temp[k++] = p->array[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = p->array[i++];
    }

    while (j <= p->fim) {
        temp[k++] = p->array[j++];
    }

    for (i = 0; i < k; i++) {
        p->array[p->inicio + i] = temp[i];
    }

    free(temp);
    pthread_exit(NULL);
}

int main() {
    int array[TAMANHO] = {7, 12, 19, 3, 18, 4, 2, 6, 15, 8};

    pthread_t threads[3];
    parameters *data = (parameters *)malloc(sizeof(parameters));

    data->array = array;
    data->inicio = 0;
    data->fim = TAMANHO - 1;

    printf("Lista Original: (");
    for (int i = 0; i < TAMANHO; i++) {
        printf(" %d,", array[i]);
    }
    printf(" )\n");

    pthread_create(&threads[0], NULL, classificar, data);
    pthread_join(threads[0], NULL);

    parameters *data1 = (parameters *)malloc(sizeof(parameters));
    data1->array = array;
    data1->inicio = TAMANHO / 2;
    data1->fim = TAMANHO - 1;

    pthread_create(&threads[1], NULL, classificar, data1);
    pthread_join(threads[1], NULL);

    parameters *data2 = (parameters *)malloc(sizeof(parameters));
    data2->array = array;
    data2->inicio = 0;
    data2->fim = TAMANHO - 1;

    pthread_create(&threads[2], NULL, mesclar, data2);
    pthread_join(threads[2], NULL);

    printf("Lista Classificada: (");
    for (int i = 0; i < TAMANHO; i++) {
        printf(" %d,", array[i]);
    }
    printf(" )\n");

    free(data);
    free(data1);
    free(data2);

    return 0;
}
