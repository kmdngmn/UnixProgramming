#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){

    FILE *fp;
    int a;
    
    system("ps");

    fp = popen("wc -l","w");
    if(fp == NULL){
        fprintf(stderr,"popen failed\n");
        exit(1);
    }


    for(a = 0; a < 100; a++){
        fprintf(fp,"test line\n");

    }
    

    printf("========\n");
    system("ps");
    pclose(fp);

    return 0;
}

