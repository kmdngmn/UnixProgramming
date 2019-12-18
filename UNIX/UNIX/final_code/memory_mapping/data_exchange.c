#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int fd;
    pid_t pid;
    caddr_t addr;
    struct stat statbuf;
    int status;

    if(argc != 2){
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    if(stat(argv[1], &statbuf)==-1){
        perror("stat");
        exit(1);
    }

    if((fd = open(argv[1], O_RDWR )) == -1){
        perror("open");
        exit(1);
    }

    addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE,MAP_SHARED,fd,(off_t)0);
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
        case 0:
            printf("1. Child Process : addr=%s", addr);
            sleep(1);
            addr[0] = 'x';
            printf("2. Child Process : addr=%s", addr);
            sleep(2);
            printf("3. Child Process : addr=%s", addr);
            break;
        default:
            printf("1. Parent Process : addr=%s", addr);
            sleep(2);
            printf("2. Parent Process : addr=%s", addr);
            addr[1] = 'y';
            printf("3. Parent Process : addr=%s", addr);
            wait(&status);
            break;
    }

    return 0;
}


