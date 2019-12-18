#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void){

    DIR *dp;

    struct dirent *dent;

    dp = opendir("ndir");

    while (dent == readdir(dp)){
        printf("%s\n",dent->d_name);
    }

    closedir(dp);


    return 0;
}
