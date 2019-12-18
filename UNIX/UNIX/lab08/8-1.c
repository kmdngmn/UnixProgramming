#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void){
    FILE *fp;
    
    fp = popen("ps","w"); // r->w
    if (fp == NULL) {
        fprintf(stderr, "popen failed\n");
        exit(1);
    }

    sleep(0.2);

    fprintf(fp,"ps:\n");

    pclose(fp);
    

    return 0;
}

