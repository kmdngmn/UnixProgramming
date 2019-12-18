#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

    char *str;

    str = malloc(sizeof(char) * 20);

    strcpy(str,"hello");
    printf("%s\n",str);

    strcpy(str,"hello world");
    printf("%s\n",str);

    free(str);

    return 0;
}
