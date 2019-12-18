#include <stdio.h>

extern int add(int a,int b);

int main(void){

    int a;

    a = add(5,3);

    printf("a=%d\n",a);

    return 0;
}
