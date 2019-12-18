#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/sysinfo.h>

int main(void){

    DIR *dp;

    struct dirent *dent;

    dp = opendir(".");

    while (dent = readdir(dp)){
        printf("name : %s, ", dent->d_name);
        printf("inode : %d\n",(int)dent->d_ino);
    }


    closedir(dp);

    return 0;
}
