#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){
    
    struct stat buf;

    stat("unix.txt",&buf);

    printf("Inode =%d\n", (int)buf.st_ino); // inode
    printf("Mode =%o\n", (unsigned int)buf.st_mode); // access mode
    printf("Nlink =%o\n", (unsigned int)buf.st_nlink); // link no
    printf("UID =%d\n", (int)buf.st_uid); // user id
    printf("GID =%d\n", (int)buf.st_gid); // user group
    printf("SIZE =%d\n", (int)buf.st_size); // file size
    printf("Atime =%d\n", (int)buf.st_atime); // access time
    printf("Mtime =%d\n", (int)buf.st_mtime); // modify time
    printf("Ctime =%d\n", (int)buf.st_ctime); // last status change time
    printf("Blksize =%d\n", (int)buf.st_blksize); // block size
    printf("Blocks =%d\n", (int)buf.st_blocks); // block no
//    printf("FStype =%s\n", buf.st_fstype); 

    int fd;

    fd = open("unix.txt",O_RDONLY);

    fstat(fd,&buf);
    // printf ~

    close(fd);
    return 0;
}
