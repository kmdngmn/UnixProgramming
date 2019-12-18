#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    FILE *rfp, *wfp;
    char buf[BUFSIZ];
    int c;

    if((rfp = fopen("unix.txt","r")) == NULL){
        perror("error");
        exit(1);
    }

    if((wfp = fopen("unix.bak","w")) == NULL){
        perror("error");
        exit(1);
    }

    while(( c = fread(buf,sizeof(char)*2,3,rfp)) > 0 ){
        if(fwrite(buf,sizeof(char)*2,c,wfp) != c){
            perror("fwrite");
        }
    }

    
    fclose(rfp);
    fclose(wfp);

    return 0;

}
