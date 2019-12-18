#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){

    int status;
    pid_t pid;

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0:
            printf("--> child process\n");
            exit(2);
            break;
        default:
            while(wait(&status) != pid){
                continue;
            }

            printf("--> parent process\n");
            printf("status: %d, %x\n",status, status);
            printf("child process exit status : %d\n",status >> 8 );
            break;
    }

    return 0;
}

