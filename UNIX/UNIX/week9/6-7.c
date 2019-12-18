#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){

    pid_t pid;

    switch(pid = fork()){
        case -1 :
            perror("fork");
            exit(1);
            break;
        case 0:
            printf("--> Child Process\n");
            if (execlp("ls", "ls", "-a", (char *)NULL) == -1){
                perror("execlp");
                exit(1);
            }
            exit(0);
            break;
        default:
            printf(" --> Parent process - My PID:%d\n",(int)getpid());
            break;
    }
    return 0;
}

