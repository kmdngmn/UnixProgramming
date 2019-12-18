#include <stdio.h>
#include <unistd.h> // getopt
#include <stdlib.h> // atoi
#include <string.h> // strcmp
#include <ctype.h>

int main(int argc, char *argv[]){
    int n;

    //extern char *optarg;
    //extern int opterr,optind;

    int mul = 1;
    int sum = 0;

    while((n=getopt(argc,argv,"ma:")) != -1) {
        for(int i = 2; i <argc; i++){
            mul *= atoi(argv[i]);
        }
        for(int i = 2; i < argc; i++){
            sum += atoi(argv[i]);
        }

        switch(n){
            case 'm': // -m
                printf("%d\n",mul);
                break;
            case 'a':
                if(strcmp(argv[1],"-am") == 0){
                    printf("%d\n%d\n", sum,mul);
                    break;
                }
                else if(strcmp(argv[1],"-a") == 0){
                    printf("%d\n",sum);

                    break;
                }
                
                break;
            default: //invalid option
                printf("Usage: error");
                break;
        }
    }


    return 0;
}


