#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){

    int fd, flags;

    fd = open("unix.txt", O_RDWR);
    if(fd == -1){
        perror("error");
        exit(1);
    }

    if((flags = fcntl(fd,F_GETFL)) == -1){
        perror("error");
        exit(1);
    }

    printf("%d\n",flags);

    flags |= O_APPEND;

    printf("%d\n",flags);

    if(fcntl(fd,F_SETFL,flags) == -1){
        perror("error");
        exit(1);
    }

    char str[10] = "hanbit\n";

    if(write(fd,str,sizeof(str)) != sizeof(str)){
        perror("error");
        exit(1);
    }
    close(fd);


    return 0;

}
