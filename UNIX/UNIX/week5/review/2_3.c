#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void){

    int fd;

    close(0);

    fd = open("unix.txt", O_RDWR);

    if(fd == -1){
        perror("error");
        exit(1);
    }

    printf("unix.txt : fd = %d\n",fd);
    close(fd);

    return 0;
}
