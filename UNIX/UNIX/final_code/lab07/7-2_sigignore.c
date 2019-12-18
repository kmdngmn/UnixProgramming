#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(void){
    int i;

    sigignore(SIGINT);

    for(i = 0; i < 10; i++){
        printf("sleep 1 second...\n");
        sleep(1);
    }
    return 0;
}

