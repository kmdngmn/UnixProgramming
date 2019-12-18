#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    FILE *rfp, *wfp;
    int c;

    rfp = fopen("unix.txt","r");
    if(rfp == NULL)
    {
        perror("unix.txt");
        exit(1);
    }

    wfp = fopen("unix.clo","w");
    if(wfp == NULL){
        perror("unix.clo");
        exit(1);
    }


    while (( c = fgetc(rfp)) != EOF){
        fputc(c,wfp);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;

}

