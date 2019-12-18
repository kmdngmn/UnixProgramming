#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){

    int rfd,wfd,n;

    char buf[BUFSIZ];

    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; //0644

    rfd = open("unix.txt",O_RDONLY);
    if(rfd == -1){
        perror("unix.txt");
        exit(1);
    }

    wfd = open("unix.bak", O_CREAT | O_EXCL | O_TRUNC | O_WRONLY, mode);
    if(wfd == -1){
        perror("unix.bak");
        exit(1);
    }

    while (( n = read(rfd, buf, sizeof(buf))) > 0){
        if ((write(wfd,buf,n)) != n){
            perror("write");
            exit(1);
        }
    }

    close(rfd);
    close(wfd);

    return 0;
}
