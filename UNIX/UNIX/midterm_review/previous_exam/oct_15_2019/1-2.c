#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){

    DIR *dp;
    struct dirent *dent;

    if((dp = opendir("/")) == NULL){
        perror("error");
        exit(1);

    }

    while (( dent = readdir(dp))){
        printf("name : %s, ",dent->d_name);
        printf("ino : %d\n", (int)dent->d_ino);
    }

    return 0;
}
