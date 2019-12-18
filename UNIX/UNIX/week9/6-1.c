#include <stdio.h>
#include <stdlib.h>

int main(void){

    int a;
    a= system("ps -ef | grep ubuntu > test.txt");

    printf("return value = %d\n",a);

    return 0;
}

