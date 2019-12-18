#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
 
    int fd;
    struct stat buf;
    fd = open("unix.txt", O_RDONLY);
    if(fd == -1)
    {
        perror("unix.txt");    
    
    }
    fstat(fd,&buf);

    printf("%d\n",(int)buf.st_ino);
    printf("%d\n",(int)buf.st_uid);

    close(fd);
    return 0;


}
