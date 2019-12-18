#include <stdio.h>
#include <unistd.h> // library for getopt
#include <stdlib.h> // library for atoi
#include <string.h> // library for strcmp

int main(int argc, char *argv[])
{

    int n;
    extern char *optarg; // extern : to use other file's global variable 
    extern int opterr, optind;

    int mul = 1;
    int sum = 0;
    while ((n=getopt(argc,argv,"ma:")) != -1) { // option m or a
        for(int i = 2; i < argc; i++){
            mul *= atoi(argv[i]);
        }
        for(int i = 2; i < argc; i++){
            sum += atoi(argv[i]);
        }

        switch(n){
            case 'm': // -m
                printf("%d\n",mul);
                break;
            case 'a': // -a
                if(strcmp(argv[1],"-am") == 0) { // -am
                    printf("%d %d\n",sum,mul);
                    break;
                }
                if(strcmp(argv[1],"-a") == 0) { // -a
                    printf("%d\n",sum);
                    break;
                }
                break;
            default: // invalid option
                printf("Usage: 1-9 [-am] n1 n2 ...\n");
                break;
        }
    }

    if(atoi(argv[1])>0) // no option = -a
    {
        sum = 0;
        for(int i = 1; i < argc; i++){
            sum+=atoi(argv[i]);
        }
        printf("%d\n",sum);
    }

    return 0;
}

