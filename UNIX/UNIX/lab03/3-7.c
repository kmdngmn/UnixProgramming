#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    char *fname; 
    char fntmp[BUFSIZ];
    char template[32];

    int fd;

    strcpy(template, "/tmp/lab03_reviewXXXXXX");
    fd = mkstemp(template);

    
    printf("TMP File Name(mkstemp) : %s\n", fname);

    close(fd);

    return 0;
}

