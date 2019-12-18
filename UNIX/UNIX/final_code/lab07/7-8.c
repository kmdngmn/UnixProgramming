#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    int fd, pagesize, length;
    pid_t pid;
    int status;

    caddr_t addr;
    
    pagesize= sysconf(_SC_PAGESIZE);
    length = 1*pagesize;


    if((fd = open("test2.txt", O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1){
        perror("open");
        exit(1);
    }

    if(ftruncate(fd, (off_t) length) == -1){
        perror("truncate");
        exit(1);
    }

    addr = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED,fd, (off_t)0);

    if(addr == MAP_FAILED){
        perror("mmap");
        exit(1);
    }
    close(fd);

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0:     // child
            printf("1. Child Process :addr=%s", addr);
            sleep(2);

            strcpy(addr,"Child Writes String");
            printf("2. Child Process :addr=%s", addr);
            sleep(3);
            printf("3. Child Process :addr=%s", addr);
            break;
        default:    // parent

            printf("1. Parent process :addr=%s", addr);
            sleep(4);
            printf("2. Parent process :addr=%s", addr);
            
            int i;
            for(i = 0; i < 20; i++){
                if((addr[i] >= 'A') && (addr[i] <= 'Z')){
                    addr[i] = addr[i] + 32;
                }
                else if((addr[i] >= 'a') && (addr[i] <= 'z')){
                    addr[i]=addr[i]-32;
                }
            }
            
            printf("3. Parent process :addr=%s", addr);
            wait(&status);
            break;
    }
    return 0;
}

