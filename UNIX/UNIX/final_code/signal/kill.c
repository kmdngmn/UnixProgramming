#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(void){
    printf("Before SIGCONT Signal to Parent.\n");

    kill(getppid(), SIGCONT);

    printf("Before SIGQUIT SIgnal to me\n");

    kill(getpid(), SIGQUIT);

    printf("After SIGQUIT Signal\n");
    
    return 0;
}
