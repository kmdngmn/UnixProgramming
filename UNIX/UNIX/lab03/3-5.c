#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// high level file I/O
int main(void){

    FILE *rfp, *wfp;
    int c;

    if((rfp=fopen("3-1.txt","r")) == NULL){ 
        perror("error");
    }
    
    if((wfp=fopen("3-5.txt","w")) == NULL){
        perror("error");
    }

    while(( c = fgetc(rfp) ) != EOF){
        fputc(c,wfp);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;
}
