#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo){
    printf("Signal handler Signal Number : %d\n", signo);
    psignal(signo, "Received Signal");
}

int main(void){
    void (*hand)(int);

    hand = signal(SIGINT, handler);
    if(hand == SIG_ERR){
        perror("signal");
        exit(1);
    }

    printf("Wait 1st Ctrl+c... : SIGINT\n");
    pause();
    printf("After 1st Signal Handler\n");
    pause();
    printf("After 2nd Signal Handler\n");

    return 0;
}

