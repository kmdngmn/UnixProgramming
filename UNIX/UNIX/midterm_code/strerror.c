#include <stdio.h>
#include <sys/errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern int errno;

int main(void){

    char *err;

    if(access("unix.txt",F_OK) == -1){
        err = strerror(errno);
        printf("error : %s\n",err);
        exit(1);
    }
    return 0;
}
