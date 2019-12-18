#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    printf("--> Before exec() system call\n");

    if(execlp("ls", "ls", "-a", "-l", (char *)NULL) == -1){
        perror("execlp");
        exit(1);
    }

    printf("--> After exec() system call\n");

    return 0;
}

