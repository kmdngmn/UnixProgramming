#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int n;

    while(( n=getopt(argc,argv, "abc:") != -1)){
        
        switch(n){
            case 'a':
                printf("a\n");
                break;
            case 'b':
                printf("b\n");
                break;
            case 'c':
                printf("c\n");
                break;
        }
    }

    return 0;
}

