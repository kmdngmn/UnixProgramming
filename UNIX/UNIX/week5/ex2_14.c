#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (void) {

    FILE *rfp, *wfp;
    char buf[BUFSIZ];
    int n;

    if ((rfp = fopen("unix.txt", "r")) == NULL){
        perror("error");
        exit(1);
    }

    if ((wfp = fopen("unix.txt", "a")) == NULL){
        perror("error");
        exit(1);
    }

    while((n = fread(buf, sizeof(char)*2, 3, rfp)) > 0 ){

        fwrite(buf,sizeof(char)*2, n, wfp);
    }
    fclose(rfp);
    fclose(wfp);

    return 0;

}
