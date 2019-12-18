#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void){
    pid_t pid, pid1, pid2;
    int i, status;

    if((pid1 = fork()) < 0){
        perror("fork");
        exit(1);
    }
    if(pid1 >0){
        printf("Parent forks 1st child\n");

        if((pid2 = fork()) < 0){
            perror("fork");
            exit(2);
        }
        if(pid2>0){
            printf("Parent forks 2nd child\n");
            printf("Parent %d waits children\n", (int)getpid());
            while((pid=wait(&status)) > 0){
                printf("Child %d exit status = %x\n", (int)pid, status);
            }
        }
        else{
            for(i = 0; i < 3; i++){
                sleep(1);
                printf("Child %d executes.\n", (int)getpid());
            }
            exit(3);
        }
    }
    else{
        for(i = 0; i < 3; i++){
            printf("Child %d executes.\n", (int)getpid());
            sleep(1);
        }
        exit(4);
    }
    return 0;
}


