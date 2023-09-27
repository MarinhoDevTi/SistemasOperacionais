#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>




int main(int argc, char * argv[]){
    pid_t pid;

    /*Fork a child process | fork cria o processo filho */
    pid = fork();

    if (pid < 0) { /* error occurred | ocorreu um erro na criacao do processo */
        fprintf (stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {  /* child process*/
        printf("[FILHO] Iniciando Tarefa");
        execlp("/bin/ls", "ls", NULL);
    } else { /* parent process*/
        /* parent will wait for the cild to complete*/
        printf("Processo PAI entrando em espera\n");
        wait(NULL);
        printf("/-/-/-/-/-/-/-/-\n");
        printf("|Child Complete|\n");
        printf("/-/-/-/-/-/-/-/-\n");
    }
    printf("[CODIGO COMUN] Finalizando \n");
    printf("/-/-/-/-/-/-/-/-\n");
    return 0;
}