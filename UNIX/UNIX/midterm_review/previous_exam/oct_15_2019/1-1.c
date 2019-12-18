#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){

    int n, rfd, wfd;

    rfd = open("a.txt",O_RDONLY);
    if(rfd == -1){
        perror("eroror");
        exit(1);
    }

    wfd = open("b.txt",O_CREAT | O_EXCL | O_TRUNC | O_WRONLY, 0644);
    
    char buf[BUFSIZ];

    while(( n = read(rfd,buf,sizeof(buf))) >0){
        if ((write(wfd,buf,n)) != n){
            perror("write");
            exit(2);
        }
    }


    close(rfd);
    close(wfd);


    return 0;
}

