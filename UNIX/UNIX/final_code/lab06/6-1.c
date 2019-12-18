#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a;
    a = system("ps -ef | grep root | head");
    printf("Return value : %d\n", a);

    return 0;
}

