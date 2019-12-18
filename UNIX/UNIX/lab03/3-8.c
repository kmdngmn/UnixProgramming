#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define SIZE 10

typedef struct Score{
    char name[SIZE];
    char kor[SIZE];
    char eng[SIZE];
    char mth[SIZE];
}Score

Score scores[SIZE];

int main(void){

    FILE *rfp, *wfp;
    char buf[BUFSIZ];
    char bufFile[BUFSIZ];

    int n;

    int count = 0;
    int sum = 0;
    double avg = 0;

    int max = 0;

    if((rfp = fopen("3-8.dat","r")) == NULL){
        perror("error");
    }

    if((wfp = fopen("3-8.out","w")) == NULL){
        perror("error");
    }

    while(!feof(rfp)){
        
        Score score;
        
        fgets(buf, BUFSIZ, rfp);

        char *ptr = strtok(buf,"\t");
        strcpy(scores.name, ptr);
        ptr = strtok(NULL, " \n");
        strcpy(scores.kor,ptr);
        ptr = strtok(NULL, " \n");
        strcpy(scores.eng,ptr);
        ptr = strtok(NULL, " \n");
        strcpy(scores.mth,ptr);
        scores[count++] = score;
      
        
    }
    for(int i = 1; i < count; i++){
        printf("%s, %s, %s\n", scores[i].kor , scores[i].eng, scores[i].mth);
    }

    char *token = strtok(buf,"\t");

    printf("%s\n",buf);
    printf("%d\n",token[1]);

    fclose(rfp);
    fclose(wfp);

    return 0;
}
