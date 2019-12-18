#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

    int fd, n;              // fd : file descriptor
    off_t start, cur;       // start, cur : offset type
    char buf[256];  

    fd = open("3-1.txt", O_RDONLY);     // open file 3-1.txt (Only Read), fd:3 
    if(fd == -1){
        perror("error");
        exit(1);
    }

    start = lseek(fd,0,SEEK_CUR);     
    // lseek : set offset, start = lseek(fd,0,SEEK_CUR) : Current offset + 0 -> start
    n = read(fd, buf, 255);             
    buf[n] = '\0';          // last character -> null
    printf("Offset start=%d, Read Str=%s, n=%d\n", (int)start, buf, n); // String is saved in buf
    cur = lseek(fd, 0 , SEEK_CUR);      // Current offset + 0 -> cur
    printf("Offset cur=%d\n", (int)cur);

    start = lseek(fd, 7, SEEK_SET);     // SEEK_SET : Start Offset, 0 + 7 -> start
  //  printf("fd:%d\n",fd); // 0:stdin, 1:stdout, 2:stderr, 3:fd, 4:and so on...
    n = read(fd, buf, 255);
    buf[n] = '\0';
    printf("Offset start=%d, Read Str=%s\n", (int)start, buf);

    close(fd);

    return 0;
}
