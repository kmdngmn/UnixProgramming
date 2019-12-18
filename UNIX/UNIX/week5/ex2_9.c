#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    int fd, flags;

    fd = open("unix.txt", O_RDWR);
    if (fd == -1){
        perror("open");
        exit(1);
    }

    flags |= O_APPEND;

    if(fcntl(fd, F_SETFL, flags) == -1){
        perror("fcntl");
        exit(1);
    }

    char str[10] = "Hanbit";
    if(write(fd, str, sizeof(str) ) != sizeof(str)){
        perror("write");
    }

    close(fd);


    return 0;
}

