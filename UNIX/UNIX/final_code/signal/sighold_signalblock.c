#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo){
    char *s;

    s = strsignal(signo);
    printf("Received Signal : %s\n", s);
}

int main(void){
    if(signal(SIGINT, handler) == SIG_ERR){
        perror("signal");
        exit(1);
    }

    sighold(SIGINT);

    pause();

    return 0;
}

