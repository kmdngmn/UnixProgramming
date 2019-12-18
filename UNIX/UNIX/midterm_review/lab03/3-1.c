#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


int main(void){

    int fd;
    mode_t mode;

    int n;

    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    char str[] = "UNIX PROGRAMMING\n";

    fd = open("3-1.txt",O_WRONLY);
    if(fd == -1){
        perror("3-1.txt");
        exit(1);
    }

    if((n = write(fd,str,strlen(str))) != strlen(str)){
        perror("write");
        exit(1);
    }




    close(fd);

    return 0;
}

