#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void){

    struct dirent *dent;

    DIR *dp;

    dp = opendir("test_directory");

    while (( dent = readdir(dp) )) {
        printf("Name : %s ", dent->d_name);
        printf("Inode : %d\n", (int)dent->d_ino);
    }

    closedir(dp);

    return 0;
}
