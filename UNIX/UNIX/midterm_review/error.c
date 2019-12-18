#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void){

    if (access("unix.txt",F_OK) == -1){
        perror("superpowererror");
        exit(1);
    }

    return 0;
}
