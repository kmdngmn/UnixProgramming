#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void handler(int signo){
    printf("catch SIGINT...\n");
}

int main(void){
    int i;

    signal(SIGINT,handler);

    while(1){
        printf("sleep 1 second...\n");
        sleep(1);
    }
    return 0;
}

