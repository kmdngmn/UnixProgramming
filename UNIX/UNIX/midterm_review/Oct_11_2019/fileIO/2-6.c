#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    FILE *rfp, *wfp;
    int n;
    
    char id[10];
    int s1,s2,s3,s4,s5;

    rfp = fopen("score.txt","r");
    if(rfp == NULL){
        perror("rfp");
        exit(1);
    
    }

    wfp = fopen("average.txt","w");
    if(wfp == NULL){
        perror("wfp");
        exit(1);
    }

    fprintf(wfp, "average is .... not bad..\n");

    while (( n = fscanf(rfp,"%s %d %d %d %d %d\n",&id,&s1,&s2,&s3,&s4,&s5)) !=EOF){
        fprintf(wfp,"%s : %d\n",id, (s1+s2+s3+s4+s5)/5);
    }


    fclose(rfp);
    fclose(wfp);
    return 0;
}

