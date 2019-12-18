#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

int main(void){

    
    int fd;
    
    fd = open("tmp.ccc",O_CREAT | O_WRONLY, 0644);
    if(fd == -1){
        perror("unix.txt");
        exit(1);

    }

    dup2(fd,1);

    printf("hello fucking world\n");
    printf("fd = %d\n",fd);


    
    close(fd);
    

    return 0;
}
