#include <stdio.h>
#include <stdlib.h>

void cleanup1(){
    printf("Cleanup 1 is called\n");
}

void cleanup2(){
    printf("Cleanup 2 is called\n");
}

int main(void){
    atexit(cleanup1);
    atexit(cleanup2);

    exit(0);
    return 0;
}

