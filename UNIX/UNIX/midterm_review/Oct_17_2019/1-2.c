#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

//fgetc fread
int main(void){

    FILE *rfp,*wfp;
    char buf[BUFSIZ];
    int c;

    rfp = fopen("a.txt","r");
    wfp = fopen("d.txt","w");

    
    while (( c = fread(buf,sizeof(char)*2,3,rfp)) > 0){
        fwrite(buf,sizeof(char)*2,c,wfp);
    }



    fclose(rfp);
    fclose(wfp);

    return 0;
}
