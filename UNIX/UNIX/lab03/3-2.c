#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){

    int fd;
    int n;

    char str[] = "UNIX SYSTEM PROGRAMMING";

    fd = open("3-1.txt",O_WRONLY);
    if(fd == -1){
        perror("error");
        exit(1);
    
    }

    n = write(fd, str, strlen(str));

    if( n != strlen(str)){
        perror("error");
        exit(2);
    }

    close(fd);


}
