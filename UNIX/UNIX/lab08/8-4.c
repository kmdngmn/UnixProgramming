#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char str[] = "Test string ";
char buf[sizeof(str)];

void removeEnd(char *str){ // remove a last chararcter
    int i = 0;
    while(str[i]){
        i++;
    }
    str[i-1]='\0';
}

int main(void){
    int pd1[2], pd2[2];
    pid_t pid;
    int len, status;
    strcpy(buf,str);
    while(buf[0] != '\0'){
        if(pipe(pd1) == -1){
            perror("pipe");
            exit(1);
        }
        if(pipe(pd2) == -1){
            perror("pipe");
            exit(1);
        }
        switch(pid=fork()){
            case -1: /* fork error */
                perror("fork");
                exit(1);
                break;
            case 0: /* child */
                close(pd1[1]);
                close(pd2[0]);

                len = read(pd1[0],buf,sizeof(buf));
                write(1,"Child Process:", 15);
                write(1, buf, len);
                printf("\n");
                sleep(1);
                close(pd1[0]);

                removeEnd(buf);
                write(pd2[1],buf,sizeof(buf));
                sleep(1);
                close(pd2[1]);
                break;
            default: /* parent */
                close(pd1[0]);
                close(pd2[1]);
                
                removeEnd(buf);
                write(pd1[1],buf,sizeof(buf));
                sleep(1);
                close(pd1[1]);

                len = read(pd2[0],buf,sizeof(buf));
                if(buf[0]=='\0'){
                    system("pkill -9 8-4");
                }
                else{
                    write(1,"Parent Process:", 15);
                }

                write(1,buf,len);
                printf("\n");
                waitpid(pid, &status, 0);
                close(pd2[0]);
                break;
        }
    }
    return 0;
}            
