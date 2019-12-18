#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

struct sigaction act;

void handler(int signo){
    printf("Received SIGINT..\n");
    ;
}

void alramHandler(int signo){

    psignal(signo, "Received Signal");

    act.sa_flags = 0;
    act.sa_handler = NULL;

    sigaction(SIGINT, &act, (struct sigaction *)NULL);

}

int main(void){

    act.sa_flags=0;
    act.sa_handler = handler;
    
    signal(SIGALRM, alramHandler);
    alarm(30);

    if(sigaction(SIGINT, &act, (struct sigaction *)NULL) < 0){
        perror("sigaction");
        exit(1);
    }
    while(1){
        printf("wait...\n");
        pause();
    }
    return 0;
}

