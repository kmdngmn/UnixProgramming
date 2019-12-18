#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("--> Before exec function\n");

    if(execlp("ls", "ls", "-a", (char *)NULL) == -1){
        perror("execlp");
        exit(0);
    }

    printf("--> After exec function\n");

    return 0;
}

