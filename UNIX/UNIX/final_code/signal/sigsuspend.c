#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo){
    psignal(signo, "Received Signal:");
}

int main(void){
    sigset_t set;

    signal(SIGALRM, handler);

    sigfillset(&set);
    sigdelset(&set, SIGALRM);
    sigdelset(&set, SIGINT);

    alarm(3);

    printf("Wait...\n");

    sigsuspend(&set);

    return 0;
}

