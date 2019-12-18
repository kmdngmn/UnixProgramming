#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){

    int fd[2];
    pid_t pid;
    char buf[256];

    int len,status;

    if(pipe(fd) == -1){
        perror("pipe");
        exit(1);
    }

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0:

            close(fd[1]);
            write(1,"Child Process:",15);
            len = read(fd[0], buf, 256);
            write(1, buf,len);
            close(fd[0]);


            break;
        default :
        
            close(fd[0]);
            write(fd[1], "PipeLining Message\n",20);
            close(fd[1]);
            waitpid(pid,&status,0);

            break;
    }
   

    return 0;
}

