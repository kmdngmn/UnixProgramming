#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>


int main(void){

    DIR *dp;
    struct dirent *dent;

    if((dp = opendir(".")) == NULL){
        perror("error");
        exit(1);
    }
    
    while (( dent = readdir(dp))){
        printf("%s, ", dent->d_name);
        printf("%d\n",(int)dent->d_ino);
    }
    closedir(dp);


    return 0;
}
