#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){

    if(access("unix.txt",W_OK) == -1){
        perror("unix.txt");
        exit(1);
    }

    return 0;
}
