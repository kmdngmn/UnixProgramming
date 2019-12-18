#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    int status;
    pid_t pid;

    switch(pid=fork()){
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0:
            printf("--->child process\n");
            exit(2);
            break;
        default:
            
            wait(&status);

            printf("--->Parent process\n");
            printf("Status: %d, %x\n", status, status);
            printf("Child process Exit Status: %d\n", status >> 8);
            break;
    }
    return 0;
}

