#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    int status;
    pid_t pid;

    if((pid = fork()) < 0 ){
        perror("fork");
        exit(1);
    }

    if(pid == 0){
        printf("---> Child Process\n");
        sleep(3);
        exit(3);
    }

    printf("---> Parent Process\n");

    while(waitpid(pid,&status,WNOHANG) == 0){   // option- WCONTINUED, WNOHANG
        printf("Parent still wait...\n");
        sleep(1);
    }

    printf("Child Exit Status : %d\n", status >> 8);

    return 0;
}

