#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void){
    
    signal(SIGINT, SIG_IGN);

    printf("1st..\n");
    pause();
    printf("2nd..\n");
    pause();

    return 0;
}

