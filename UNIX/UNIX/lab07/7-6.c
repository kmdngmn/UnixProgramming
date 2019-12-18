#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

struct sigaction act;

void handler(int signo){
    psignal(signo, "Received Signal:");
    sleep(3);
    printf("In Signal Handler, After Sleep\n");
}
void alarmHandler(int signo){
    psignal(signo, "Received Signal:");

    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_handler=NULL; // release handler
    sigaction(SIGINT, &act, (struct sigaction *)NULL);
 
    printf("After alarmHandler\n");
}


int main(void){

    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    act.sa_handler = handler;

    signal(SIGALRM, alarmHandler);
    alarm(30); // occur signal after 30sec

    if(sigaction(SIGINT, &act, (struct sigaction *)NULL) <0){
        perror("sigaction");
        exit(1);
    }

    while(1){
        fprintf(stderr, "Input SIGINT: ");
        pause();
        fprintf(stderr, "After Signal Handler\n");
    }

    return 0;
}

