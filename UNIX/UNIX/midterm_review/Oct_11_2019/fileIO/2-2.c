#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void){

    int rfd, wfd, n;
    char buf[10];

    rfd = open("lastclone.txt",O_RDONLY);
    if(rfd == -1){
        perror("lastclone.txt");
        exit(1);
    }

    wfd = open("clone.txt", O_CREAT | O_EXCL | O_TRUNC | O_WRONLY, 0644);
    if(wfd == -1){
        perror("clone.txt");
        exit(1);
    }

    while(( n = read(rfd,buf,sizeof(buf))) > 0){
        if(write(wfd,buf,n) != n){
            perror("write");
        }
    }

    close(rfd);
    close(wfd);

    return 0;
}

