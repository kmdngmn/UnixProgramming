#include <stdio.h>
#include <sys/times.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define CLK_TCK ((clock_t) sysconf(3)) /* 3 is _SC_CLK_TCK */

int main(void){

    int i;
    time_t t;
    struct tms mytms;
    clock_t t1, t2;

    if(( t1 = times(&mytms)) == -1){
        perror("times 1");
        exit(1);
    }

    for(i = 0; i <= 1000000; i++){
        time(&t);
        printf("%d\n", i);
    }

    if(( t2 = times(&mytms)) == -1){
        perror("times 2");
        exit(1);
    }


    printf("Real time : %.1f sec\n",(double)(t2-t1)/CLK_TCK);
    printf("User time : %.1f sec\n",(double)mytms.tms_utime /CLK_TCK);
    printf("System time : %.1f sec\n",(double)mytms.tms_stime /CLK_TCK);

    return 0;
}

