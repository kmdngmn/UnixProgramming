#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo){
    printf("Signal handler Signal Number : %d\n", signo);
    psignal(signo, "Received Signal");
}

int main(void){

    if(signal(SIGINT,handler) == SIG_ERR){
        perror("signal");
        exit(1);
    }

    sigignore(SIGINT);

    printf("Wait 1st Ctrl+c... : SIGINT\n");
    pause();
    printf("After 1st Signal Handler\n");
    pause();
    printf("After 2nd Signal Handler\n");

    return 0;
}

