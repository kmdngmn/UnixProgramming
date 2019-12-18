#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void){
    FILE *fp;
    int a;

    fp = popen("wc -l", "w");

    if(fp == NULL){
        fprintf(stderr, "popen failed\n");
        exit(1);
    }

    for( a=0; a<100; a++){
        fprintf(fp, "test line\n");
    }
    pclose(fp);

    return 0;
}

