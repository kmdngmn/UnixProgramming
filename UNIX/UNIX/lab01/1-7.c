#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) // argc : argument count, argv : argument vector
{
    int i, sum = 0;

    for(i = 1; i < argc; i++)
        sum += atoi(argv[i]); // atoi function : String -> Integer
    printf("%d\n",sum);

    return 0;
}

