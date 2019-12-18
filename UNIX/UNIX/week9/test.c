#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    

    if(access("unix.txt",F_OK) == -1){
        perror("error");
        exit(1);
    }

    printf("helloworld");




    return 0;
}
