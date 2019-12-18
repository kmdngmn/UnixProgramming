#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){

    int fd;
    fd = open("tmp.bbb", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if(fd == -1){
        perror("error");
        exit(1);
    }

    dup2(fd, 1);

    printf("DUP2 : Hello  Standard Output Redirection\n");

    close(fd);



    return 0;
}

