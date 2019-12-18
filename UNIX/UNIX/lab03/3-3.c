#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {

    int rfd, wfd, n;
    char buf[BUFSIZ];

    rfd = open("3-1.txt", O_RDONLY);
    if(rfd == -1){
        perror("read error");
        exit(1);
    }

    wfd = open("3-3.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(wfd == -1){
        perror("write error");
        exit(1);
    }

    while ((n = read(rfd,buf,1) > 0)){
        
        if(write(wfd,buf,n) !=n ){
            perror("error");
            exit(1);
        }
        
        if(n == -1){
            perror("error");
            exit(1);
        }
    }

    close(rfd);
    close(wfd);
    
    return 0;
}

