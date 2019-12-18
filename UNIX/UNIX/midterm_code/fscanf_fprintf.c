#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    FILE *rfp,*wfp;

    char name[10];
    int s1,s2,s3;

    if((rfp = fopen("unix.dat","r")) == NULL){
        perror("error");
        exit(1);
    }

    if((wfp = fopen("average.dat","w")) == NULL){
        perror("error");
        exit(1);
    }

    fprintf(wfp, "average is ...\n");
    while (( fscanf(rfp,"%s %d %d %d",name,&s1,&s2,&s3)) > 0){
        fprintf(wfp,"%s : %.2f\n",name,(float)((s1+s2+s3)/3.0));
    }


    fclose(rfp);
    fclose(wfp);


    return 0;
}

