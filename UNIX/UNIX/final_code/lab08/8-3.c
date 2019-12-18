#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){
    int pd[2];

    pid_t pid;

    char str[] = "Pipe Test";
    char buf[256];
    int len, status;

    if(pipe(pd) == -1){
        perror("pipe");
        exit(1);
    }

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0:
            close(pd[1]);
            write(1,"from parent:",12);
            len = read(pd[0],buf,256);
            write(1,buf,len);
            close(pd[0]);
            write(1,"\n",1);
            break;

        default:
           close(pd[0]);
           write(pd[1], str, sizeof(str));
           close(pd[1]);

           wait(&status);

           break;
    }

    return 0;
}


