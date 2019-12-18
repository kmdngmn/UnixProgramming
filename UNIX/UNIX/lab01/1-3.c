#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // library for exit(1)

int main(void)
{
    if(access("linux.txt", F_OK) == -1){ // if lunux.txt is existed?
        perror("linux.txt"); // print error
        exit(1); // system call
    }

    return 0;
}
