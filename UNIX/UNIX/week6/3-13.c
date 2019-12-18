#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){

    if (mkdir("han",0755) == -1){
        perror("han");
        exit(1);
    }
    
    printf("mkdir han\n");
    system("ls -l");

    if (mkdir("bit",0755) == -1){
        perror("bit");
        exit(1);
    }
    printf("mkdir bit\n");
    system("ls");

    if (rename("han", "hanbit") == -1){
        perror("rename");
        exit(1);
    }
    printf("rename hanbit\n");
    system("ls");

    if (rmdir("bit") == -1){
       perror("bit");
       exit(1);
    }
    printf("rmdir bin\n");
    system("ls");

    return 0;

}

