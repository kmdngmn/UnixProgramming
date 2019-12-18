#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){ // argc : argument count , argv : argument vector

    int i;
    int s = 0; // sum
    for(i = 1; i < argc; i++){
        s += atoi(argv[i]); //  atoi :char -> integer 
                            // sum of arguments
                             
    }

    printf("%d\n",s);       // print sum 
    printf("%d\n",s/(i-1)); // print average

    return 0;
}

