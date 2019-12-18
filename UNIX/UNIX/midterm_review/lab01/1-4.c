#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

extern int errno;

int main(void){

    char *str;

    if(access("linux3.txt",F_OK) == -1){

        str = strerror(errno);

        printf("linux3.txt : %s\n",str);

        exit(1);
    }



    return 0;
}
