#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    /* fork a child process*/
    pid = fork();

    if (pid < 0 ) { /* error ocurred*/
    fprintf(stderr, "Fork Failed");
    return 1;
    } else if (pid == 0 ){ /* child process*/
        execlp("/bin/ls", "l")

    }

    
}