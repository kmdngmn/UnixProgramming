#include <stdio.h>
#include <unistd.h>

int main(void){

    printf("_SC_ARG_MAX : %ld\n",sysconf(_SC_ARG_MAX));
    printf("_SC_CHILD_MAX : %ld\n",sysconf(_SC_CHILD_MAX));
    printf("_SC_CLK_TCK : %ld\n",sysconf(_SC_CLK_TCK));
    printf("_SC_OPEN_MAX : %ld\n",sysconf(_SC_OPEN_MAX));
    printf("_SC_VERSION : %ld\n",sysconf(_SC_VERSION));

    return 0;
}
