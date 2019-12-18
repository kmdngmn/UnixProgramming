#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    if(access("linux.txt",F_OK) == -1){
        perror("linux.txt");
        exit(1);
    }


    return 0;
}
