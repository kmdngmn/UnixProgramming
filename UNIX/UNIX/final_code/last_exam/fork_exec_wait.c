#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

int main(void){
    pid_t pid;
    int status;

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0:
            printf("--->Child Process\n");
            if(execlp("ls", "ls", "-a", (char *)NULL) == -1){
                perror("execlp");
                exit(1);
            }
            exit(0);
            break;

        default:
            printf("--->Parent Process\n");
            wait(&status);
            break;
    }
    return 0;

}
