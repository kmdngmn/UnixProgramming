#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){

    int rfd,wfd,n;
    char buf[BUFSIZ];

    rfd = open("unix.txt",O_RDONLY);
    if (rfd == -1){
        perror("error");
    }

    wfd = open("unix.in",O_CREAT | O_EXCL | O_TRUNC | O_WRONLY,0644);
    if (wfd == -1){
        perror("error");
        exit(1);
    }

    while (( n = read(rfd,buf,sizeof(buf))) > 0){

        if (( write(wfd,buf,n) ) != n){
            perror("write");
        }
    }




    close(rfd);
    close(wfd);


}
