#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

off_t lseek(int fildes, off_t offset, int whence);

int main(void){

    int fd, n;
    off_t start,cur;
    char buf[256];

    fd = open("unix.txt", O_RDONLY);
    if(fd == -1){
        perror("Open unix.txt");
        exit(1);
    }
    
    start = lseek(fd,0,SEEK_CUR);

    n = read(fd, buf,255);
    buf[n] = '\0';
    printf("Offset start=%d, Read Str=%s, n=%d\n", (int)start, buf, n);

    cur = lseek(fd,0,SEEK_CUR);
    printf("Offset cur=%d\n", (int)cur);

    start = lseek(fd, 4, SEEK_SET);
    n= read(fd, buf, 255);
    buf[n] = '\0';
    printf("Offset start=%d, Read Str=%s", (int)start, buf);

    close(fd);

    return 0;

}
