#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *rfp;

    int id, s1, s2, s3, s4, n;

    if ((rfp = fopen("unis.dat", "r")) == NULL){
    
        perror("fopen: unix error");

        exit(1);
    
    }
 
    printf("Student Id average");

    while((n=fscanf(rfp, "%d %d %d %d %d", &id,&s1,&s2,&s3,&s4)) != EOF){
        printf("%d : %d\n", id, (s1+s2+s3+s4)/4);
    }

    fclose(rfp);
    
    return 0;
    



}

