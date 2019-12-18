#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/errno.h>

int main(void){
    
    struct stat bufbuf;

    lstat("unix.sym",&bufbuf);
    printf("link count : \n", (int)bufbuf.st_nlik);

    char buf[BUFSIZ];
    readlink("unix.sym",buf,BUFSIZ);
    printf("-> %s\n",buf);

    realpath("unix.sym", buf);
    printf("path : %s\n",buf);
    
    

    return 0;
}

