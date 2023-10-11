#include <stdio.h>
#include <unistd.h>


int main() {
    int i;
    pid_tgetpid();

    for (i = 0; i < 4; i++) {
        fork();
         // ?????
    }
    return 0;
}