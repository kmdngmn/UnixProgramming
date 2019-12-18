#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    char *str;
    str = malloc(sizeof(char) * 20); // dynamic memory allocation, size = 20

    strcpy(str,"Hello"); // string copy, str = "Hello";
    printf("%s\n", str);

    strcpy(str,"Good morning");
    printf("%s\n",str);

    free(str); // free memory
    return 0;
}
