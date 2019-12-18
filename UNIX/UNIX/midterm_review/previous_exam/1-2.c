#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

int main(void){

    struct dirent *dent;
    DIR *dp;

    if ((dp = opendir("/")) == NULL){
        perror("/ error");
        exit(1);
    }
    while((dent = readdir(dp))){
        printf("name : %s, ", dent->d_name);
        printf("inode : %d\n", (int)dent->d_ino);
    }



    closedir(dp);


    return 0;
}

