#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){

    struct stat buf;

   
    link("unix.txt","unix.hl");

    symlink("unix.txt","unix.sl");

    
    lstat("unix.sl",&buf);

    printf("%d\n",(int)buf.st_nlink);


    char lbuf[256];
    readlink("unix.sl",lbuf,sizeof(lbuf));
    printf("%s\n",lbuf);

    realpath("unix.sl",lbuf);
    printf("%s\n",lbuf);


    return 0;

}

