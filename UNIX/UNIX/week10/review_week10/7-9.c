#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signo){
    psignal(signo,"Received Signal");
}

int main(void){

    signal(SIGALRM,handler);

    alarm(2);
    printf("Wait...\n");
    sleep(5);

    return 0;
}

