#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
    int fd;
    pid_t pid;
    caddr_t addr;
    struct stat statbuf;

    stat(argv[1],&statbuf);

    fd = open(argv[1], O_RDWR);

    addr = mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0);

    close(fd);

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0:
            printf("1.child process : addr=%s", addr);
            sleep(1);
            addr[0] = 'x';
            printf("2.child process : addr=%s", addr);
            sleep(2);
            printf("3.child Process : addr=%s", addr);
            break;
        default :
            printf("1.Parent process : addr=%s", addr);
            sleep(2);
            printf("2.Parent process : addr=%s",addr);
            addr[1] = 'y';
            printf("3.Parent process : addr=%s", addr);
            break;
    }


    return 0;
}


