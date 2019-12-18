#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void){

//    link("unix.txt","unix.clo"); // hard link

    symlink("unix.txt","unix.sln");

    struct stat buf;

    char str[BUFSIZ];

    lstat("unix.sln",&buf);
    printf("link : %d\n",(int)buf.st_nlink);

    readlink("unix.sln",str,sizeof(str));
    printf("%s\n",str);

    realpath("unix.sln",str);
    printf("%s\n",str);


    return 0;
}

