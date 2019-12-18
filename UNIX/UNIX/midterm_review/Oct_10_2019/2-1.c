#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define MAXLINE 1000

int main(int argc, char *argv[]){
    

    int n;

    while((n=getopt(argc,argv,"ma:")) != -1){

        int sum = 0;
        int mul = 1;

        for(int i = 2; i<argc; i++){
            sum += atoi(argv[i]);
        }
        for(int i = 2; i<argc;i++){
            mul *= atoi(argv[i]);
        }

        switch(n){
            case 'a':

                if(strcmp(argv[1],"-a")==0){

                    printf("%d\n",sum);
                    break;
                }
                else if(strcmp(argv[1],"-am")==0){
                    printf("%d %d\n",sum,mul);
                    break;
                }

            case 'm':
                printf("%d\n",mul);
                break;

            default:
                printf("Usage: 1-9 ~\n");
                break;

        }

    
    }

    if(atoi(argv[1]) > 0){

        int sum = 0;
        for(int i = 1; i < argc; i++){
            sum += atoi(argv[i]);
        }
        printf("%d\n",sum);
    }


    return 0;
}
