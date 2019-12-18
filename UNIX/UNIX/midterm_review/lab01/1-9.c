#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    int n;
    extern char *optarg;
    extern int opterr,optind;
    
//    opterr = 0;
    int mul =1;
    int sum = 0;

    while((n=getopt(argc,argv,"ma:")) != -1) { 
        for(int i = 2; i < argc; i++){
            mul *= atoi(argv[i]);
        }
        for(int i = 2; i < argc; i++){
            sum += atoi(argv[i]);
        }

        switch(n){
            case 'm':
                printf("%d\n",mul);
                break;
            case 'a':
                if(strcmp(argv[1],"-am") == 0){
                    printf("%d %d\n",sum,mul);
                    break;
                }
                if(strcmp(argv[1],"-a") == 0){
                    printf("%d\n",sum);
                    break;
                }
                break;
            default:
                perror("Usage");
                exit(1);
                break;

        }
    }

    if(atoi(argv[1]) > 0)
    {
        sum = 0;
        for(int i = 1; i < argc; i++){
            sum+=atoi(argv[i]);
        }
        printf("%d\n",sum);
    }

    return 0;
}
