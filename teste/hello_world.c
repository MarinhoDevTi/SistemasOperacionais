#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include<wait.h>



int main(int argc, char * argv[]){
    pid_t pid;
    int i;

    /*Fork a child process | fork cria o processo filho */
    pid = fork();

    if (pid < 0) { /* error occurred | ocorreu um erro na criacao do processo */
        fprintf (stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {  /* child process*/
        printf("[FILHO ] EXECUTANDO AQUI .......\n");
        //execlp("/bin/ls", "ls", NULL);
    } else { /* parent process*/
        /* parent will wait for the cild to complete*/
        printf("[PAI] Executando este trecho....\n");
        //wait(NULL);
        printf("/-/-/-/-/-/-/-/-\n");
        printf("[PAI] Processo filho terminou ... continua ...|\n");
        printf("/-/-/-/-/-/-/-/-\n");
    }
    printf("[CODIGO COMUN] Finalizando \n");
    printf("/-/-/-/-/-/-/-/-\n");
    return 0;
}