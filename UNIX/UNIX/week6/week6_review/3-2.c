#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(void){

    DIR *dp;
    struct dirent *dent;

    if ((dp = opendir("hanbit")) == NULL){
        perror("opendir");
        exit(1);
    }

    printf("** Directory content **\n");
    printf("start offset : %ld\n", telldir(dp));

    while((dent = readdir(dp))) {
        printf("Read : %s " , dent->d_name);
        printf("Current offset : %ld\n", telldir(dp));
    }

    printf("** Directory Pointer Rewind **\n");
    rewinddir(dp);
    printf("cur offset : %ld\n", telldir(dp));

    printf(" ** Move directory pointer ** \n");
    
    seekdir(dp,24);
    printf("cur offset : %ld\n", telldir(dp));

    dent = readdir(dp);
    printf("Read %s \n", dent->d_name);
    printf("Next Offset : %ld\n",telldir(dp));

    closedir(dp);

    return 0;

}

