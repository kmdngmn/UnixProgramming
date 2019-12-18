#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

struct sigaction act;

void handler(int signo){
    psignal(signo, "Received Signal:");
    sleep(1);
}

void alarmHandler(int signo){


    printf("alramHandler./..\n");
    act.sa_handler = NULL;
    sigaction(SIGINT, &act, (struct sigaction*)NULL);

}

int main(void){
    
    act.sa_flags = 0;
    act.sa_handler = handler;

    signal(SIGALRM, alarmHandler);
    alarm(30);

    sigaction(SIGINT, &act, (struct sigaction *)NULL);

    while(1){
        printf("wait signal..\n");
        pause();
    }

    return 0;
}

