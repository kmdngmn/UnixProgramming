#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){

    int fd, fd1;

    fd = open("tmp.aaa",O_CREAT | O_WRONLY | O_TRUNC, 0644);

    printf("%d\n",fd);

    close(1);

    fd1 = dup(fd);
    printf("dup fd=%d\n",fd1);
    printf("output\n");


    close(fd);
    return 0;
}
