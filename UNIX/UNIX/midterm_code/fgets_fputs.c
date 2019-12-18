#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    FILE *rfp, *wfp;
    char buf[BUFSIZ];

    if((rfp = fopen("unix.txt","r")) == NULL){
        perror("error");
        exit(1);
    }

    if((wfp = fopen("unix.out","w")) == NULL){
        perror("error");
        exit(1);
    }

    while (fgets(buf,BUFSIZ,rfp) != NULL){
        fputs(buf,wfp);
    }  


    fclose(rfp);
    fclose(wfp);

    return 0;
}
