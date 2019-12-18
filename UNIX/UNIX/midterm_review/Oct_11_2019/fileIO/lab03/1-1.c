#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void){

    FILE *rfp, *wfp;
    int n;
    char buf[BUFSIZ];

    int s1,s2,s3;

    rfp = fopen("score.txt","r");

    wfp = fopen("average.txt","w");

    fprintf(wfp,"average is ...");

    while (( n = fscanf(rfp,"%d %d %d",&s1,&s2,&s3)) > 0){
        
        fprintf(wfp,"average is : %d\n", (s1+s2+s3)/3);

    }

    fclose(rfp);
    fclose(wfp);
             

    return 0;
}

