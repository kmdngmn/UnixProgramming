#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    int pd[2];
    char str[] = "Pipe Test\n";
    char buf[256];
    int len, status;
    pid_t pid;

    if (pipe(pd) == -1){
        perror("pipe");
        exit(1);
    }

    switch(pid = fork()){
        case -1: // fork error
            perror("fork");
            exit(1);
            break;
        case 0: // child
            close(pd[1]);
            write(1, "From Parent :",14);
            len = read(pd[0], buf, 256);
            write(1, buf, len);
            close(pd[0]);
            break;
        default : // parent
            close(pd[0]);
            buf[0] = '\0';
            write(pd[1], str,sizeof(str));
            close(pd[1]);
            waitpid(pid,&status,0);
            break;
    }

 

    return 0;
}

