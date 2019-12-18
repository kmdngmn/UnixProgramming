#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void){

    FILE *rfp,*wfp;
    int n;
   

    int a,b,c,d,e;

    if(( rfp = fopen("ftext1.txt","r")) == NULL){
        perror("text1");
        exit(1);
    }

    if(( wfp = fopen("ftext2.txt","a")) == NULL){
        perror("text2");
        exit(1);
    }
   
    while (( n = fscanf(rfp,"%d %d %d %d %d",&a,&b,&c,&d,&e)) != EOF){
        fprintf(wfp,"%d %d %d %d %d\n",a,b,c,d,e);
    }

    
    fclose(rfp);
    fclose(wfp);

    return 0;
}

