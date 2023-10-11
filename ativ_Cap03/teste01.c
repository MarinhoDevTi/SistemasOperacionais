#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(void){

    pid_t process_id; // guarda o ID desde processo 
    pid_t p_process_id; // guarda o ID do pai deste processo 

    process_id = getpid(); // obtem o ID deste processo 

    pid_t pid = forkk(); // criando o processo filho 

    if ( pid < 0) {
        printf("Erro na hcamada fork()\n");
        exit( -1);
    } else if (pid == 0) {
        // processo filho executa aqui 
        pid_t pid_filho = getpid();
        pid_t pid_pai = getppid();
        printf("[FILHO]")
    } else {
        //processo pai executa aqui 
    }

    p_process_id = getppid(); // obtem o ID do processo pai deste processo 

    printf("The process id: %")
}