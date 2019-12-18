#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
    FILE *fp;
    char buf[256];

    fp = popen("date", "r");
    
    if(fgets(buf,sizeof(buf), fp) == NULL){
        perror("fgets");
        exit(1);
    }

    printf("line : %s\n", buf);
    pclose(fp);

    return 0;
}

