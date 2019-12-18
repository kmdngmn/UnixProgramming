#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    FILE *fp;
    int n;
    long cur;
    char buf[BUFSIZ];

    fp = fopen("unix.txt","r");

    cur = ftell(fp);
    printf("cur=%d\n",(int)cur);

    n = fread(buf, sizeof(char),4,fp);
    buf[n] = '\0';

    printf("str=%s\n",buf);

    fseek(fp, 1, SEEK_CUR);

    cur = ftell(fp);
    printf("cur=%d\n",(int)cur);

    
    fclose(fp);
    

    return 0;

}

