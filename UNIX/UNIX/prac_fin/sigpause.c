#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


int main(void){


    printf("hello\n");

    sigpause(SIGINT);

    return 0;
}

