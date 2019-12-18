#include <stdio.h>
#include <string.h> // library for strcmp
#include <stdlib.h> // library for atoi

int main(int argc, char *argv[]) // argc : argument count , argv : argument vector
{
    int c;
    int mul = 1;
    int sum = 0;

    if(atoi(argv[1]) > 0){ // no option = -a
        for(int i = 1; i< argc; i++){
            sum += atoi(argv[i]);
        }
        printf("%d\n",sum);
    }
    while(--argc>0 && (*++argv)[0]=='-'){
        for(int i = 1; i < argc; i++){
            sum += atoi(argv[i]); // sum
        }
        for (int i = 1; i < argc; i++){
            mul *= atoi(argv[i]); // multiple
        }

        while(c=*++argv[0]){
            if(strcmp(argv[0],"a") == 0 || strcmp(argv[0],"m")==0 || strcmp(argv[0],"am") ==0){

                switch(c){
                    case 'a': // option : -a
                        printf("%d\n", sum);
                        break;
                    case 'm': // option : -m
                        printf("%d\n",mul);
                        break;
                }
                // if option : -am then execute not only case 'a' but also case 'm'
            }
            else{ // invalid option
                printf("find: illegal optin %c\n", c);
                printf("Usage: 1-8 [-am] n1 n2 ...\n");
                break;
            }
        }
    }
    return 0;
}

