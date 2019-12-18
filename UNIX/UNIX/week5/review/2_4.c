#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){

    int rfd, wfd, n;

    char buf[10];

    rfd = open("unix.txt",O_RDONLY);

    if(rfd == -1){
        perror("error");
        exit(1);
    }

    wfd = open("unix.bak", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(wfd == -1){
        perror("error");
        exit(1);
    }
    while(( n = read(rfd,buf, 6)) > 0 ){
        if(write(wfd, buf, n) != n){
            perror("error");
            exit(1);
        }
        if(n = -1){
            perror("error");
            exit(1);
        }

    }

    close(rfd);
    close(wfd);



    return 0;
}

