#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    sigset_t new;

    sigemptyset(&new);
    sigaddset(&new, SIGINT);
    sigaddset(&new, SIGQUIT);
    sigprocmask(SIG_BLOCK, &new, (sigset_t *)NULL);

    printf("Blocking Signals : SIGINT, SIGQUIT\n");
    printf("Send SIGQUIT\n");
    
    sleep(5);
    
    //kill(getpid(), SIGQUIT);

    printf("Unblocking Signals\n");
    sigprocmask(SIG_UNBLOCK, &new, (sigset_t *)NULL);

    sleep(5);


    return 0;
}

