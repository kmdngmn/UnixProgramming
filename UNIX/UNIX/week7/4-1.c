#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){

    struct utsname uts;

    if(uname(&uts) == -1){
        perror("uts");
        exit(1);
    }

    printf("OSname : %s\n", uts.sysname);
    printf("Nodename : %s\n", uts.nodename);
    printf("Release : %s\n", uts.release);
    printf("Version : %s\n", uts.version);
    printf("Machine : %s\n", uts.machine);



    return 0;

}

