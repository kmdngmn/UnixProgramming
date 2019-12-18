#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){

    FILE *rfp, *wfp;

    rfp = fopen("unix.txt","r");
    if(rfp == NULL){
        perror("open");
    }

    wfp = fopen("unix.out","w");
    if(wfp == NULL){
        perror("open");
    }

    char c;

    while(( c = fgetc(rfp) ) != EOF){
        fputc(c, wfp);
    }



    fclose(rfp);
    fclose(wfp);


    return 0;
}
