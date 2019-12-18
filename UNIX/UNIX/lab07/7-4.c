#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo){

    printf("catch SIGINT...\n");
}

int main(void){

    if(signal(SIGINT,handler) == SIG_ERR){
        perror("signal");
        exit(1);
    }

    while(1){
        printf("sleep 1 second...\n");
        sleep(1);
    }


    return 0;
}

