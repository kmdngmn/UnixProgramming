#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(void){

    int fd, n;

    off_t start,cur;

    char buf[256];

    fd = open("unix.txt", O_RDONLY);

    if( fd == -1){
        perror("error");
        exit(1);
    }

    start = lseek(fd, 0, SEEK_CUR);
    n = read(fd, buf, 255);

    buf[n] = '\0';

    printf("OFFSET start %d, READ STR = %s, n=%d\n", (int)start,buf,n);
    cur = lseek(fd, 0, SEEK_CUR);
    printf("OFFSET cur=%d\n", (int)cur);


    start = lseek(fd,5,SEEK_SET);
    n = read(fd,buf,255);
    buf[n] = '\0';
    cur = lseek(fd,0,SEEK_CUR);
    printf("OFFSET START=%d, READ STR = %s, n OFFSET = %d, CUR = %d\n",(int)start, buf,n,(int)cur);

    close(fd);
    return 0;
}
