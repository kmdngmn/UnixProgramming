#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern int errno;

int main(void){

    if(access("unix.txt",F_OK) == -1){
        printf("%d\n",errno);
    }

    return 0;
}
