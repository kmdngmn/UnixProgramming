#include <signal.h>
#include <stdio.h>

int main(void){
    sigset_t st;

    sigemptyset(&st);

    sigaddset(&st,SIGINT);
    sigaddset(&st,SIGQUIT);

    if (sigismember(&st,SIGINT))
        printf("SIGINT is setting.\n");

    if (sigismember(&st,SIGQUIT))
        printf("SIGQUIT is setting.\n");

    sigdelset(&st,SIGQUIT);

    if (sigismember(&st,SIGQUIT))
        printf("SiGQUIT is setting.\n");
    else
        printf("SIGQUIT is unsetting.\n");
    

    return 0;
}

