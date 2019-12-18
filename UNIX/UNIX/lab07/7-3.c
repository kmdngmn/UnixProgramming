#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main(void){

    sigset_t new;

    sigemptyset(&new); // signal set empty
    sigaddset(&new,SIGINT); // signal add
    sigprocmask(SIG_BLOCK,&new,(sigset_t *)NULL); // signal set block
    
    int i;
    for(i = 0; i < 10; i++){
        printf("sleep 1 second...\n");
        sleep(1);
    }

    return 0;
}

