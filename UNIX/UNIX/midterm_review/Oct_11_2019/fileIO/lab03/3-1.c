#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void){

    FILE *rfp,*wfp;
    char buf[BUFSIZ];

    rfp = fopen("3-1.txt","r");

    wfp = fopen("3-4.txt","a");
    if(wfp == NULL){
        perror("wfp");
        exit(1);
    }

    char n;
    while (( n = fgetc(rfp)) != EOF){
        fputc(n,wfp);

    }




    fclose(rfp);
    fclose(wfp);

    return 0;
}


