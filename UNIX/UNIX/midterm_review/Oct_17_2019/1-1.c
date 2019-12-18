#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    int c;
    int sum = 0;
    int mul = 1;

    while(( c = getopt(argc,argv,"ma:")) != -1){
        
        for(int i = 2; i < argc;i++){
            mul *= atoi(argv[i]);
        }
        for(int i = 2; i < argc; i++){
            sum += atoi(argv[i]);
        }


        switch(c) {
            case 'm':
                
                printf("%d\n",mul);
                break;
            case 'a':
                if((strcmp(argv[1] , "-a")) == 0){

                    printf("%d\n",sum);
                    break;
                }
                else if((strcmp(argv[1] , "-am")) == 0){
                    printf("%d %d\n",sum,mul);
                    break;
                }
            default:
                printf("Usage : \n");
                break;
        }

    }

    if(atoi(argv[1]) > 0){
        for(int i = 1 ; i < argc; i++){
            sum += atoi(argv[i]);
        }
        printf("%d\n",sum);
    }

    return 0;
}


