#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){

    FILE *rfp,*wfp;

    int c;

    if((rfp = fopen("3-2.txt","r")) == NULL){
        perror("");
    }
    if((wfp = fopen("3-5.txt","a")) == NULL){
        perror("");
    }

    while((c=fgetc(rfp)) != EOF){
        fputc(c,wfp);

    }


    fclose(rfp);
    fclose(wfp);

    return 0;
}
