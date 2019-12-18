#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    FILE *fp;

    fp = popen("ps", "w");
    if (fp == NULL){
        fprintf(stderr, "popen failed\n");
        exit(1);
    }

//    sleep(0.2);

    fprintf(fp,"ps:\n");

    pclose(fp);
}

