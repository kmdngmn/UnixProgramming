#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void){

    struct stat buf;

    symlink("unix.txt","unix.sln"); // create symbolic link file

    stat("unix.sln",&buf); // stat

    printf("link count = %d\n",(int)buf.st_nlink); // link count of original file
    printf("Inode = %d\n",(int)buf.st_ino); // print inode

    lstat("unix.sln",&buf); // stat

    printf("link count = %d\n",(int)buf.st_nlink); // link count of symbolic link file itself
    printf("Inode = %d\n",(int)buf.st_ino); // print inode
    
    system("ll unix.*");

    return 0;
}

