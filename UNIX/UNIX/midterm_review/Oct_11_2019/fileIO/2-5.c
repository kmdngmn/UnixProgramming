#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    FILE *rfp, *wfp;
    char buf[BUFSIZ];
    int n;

    int s1,s2,s3;

    rfp = fopen("score.txt","r");
    if(rfp == NULL){
        perror("rfp");
        exit(1);
    }

    wfp = fopen("unix.score","w");
    if(wfp == NULL){
        perror("wfp");
        exit(1);
    }

    fprintf(wfp,"average score is...\n");

    while (( n = fscanf(rfp,"%d %d %d", &s1, &s2, &s3)) != EOF){
        
        fprintf(wfp,"average : %d\n", (s1+s2+s3)/3);

    }



    fclose(rfp);
    fclose(wfp);


}
