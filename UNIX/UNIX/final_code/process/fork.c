#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
    pid_t pid;

    switch (pid = fork()){
        case -1:    // fork error
            perror("fork");
            exit(1);
            break;
        case 0:     // child process
            printf("Child process - My pid:%d, MyParent's pid:%d\n", (int)getpid(), (int)getppid());
            break;
        default:    // parent process
            printf("Parent process - My pid:%d, MyParent's pid:%d, MyChild's Pid:%d\n", (int)getpid(), (int)getppid(), (int)pid);
            break;
    }

    printf("end\n");

    return 0;
}            
           
