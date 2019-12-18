#include <stdio.h>

int main(void)
{
    int a;
    printf("a = ");
    scanf("%d",&a);

    if(a >= 100){
        printf(" a >= 100\n");

    }
    else if(a >= 50 && a < 100){
        printf(" 50 <= a < 100\n");
    }
    else{
        printf(" a < 50\n");
    }


    return 0;
}

