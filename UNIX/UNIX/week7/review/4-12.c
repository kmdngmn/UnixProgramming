#include <stdio.h>
#include <time.h>

int main(void){

    time_t t;

    time(&t);

    printf("%d\n",(int)t);
    printf("%s\n",ctime(&t));

    return 0;
}
