#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void){

    int fd;
    mode_t mode;

    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    fd = open("unix2.txt",O_CREAT | O_EXCL ,mode);

    if (fd == -1){
        perror("error");
        exit(1);
    }

    close(fd);

    return 0;
}

