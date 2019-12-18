#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(void){
    
    time_t tt;

    time(&tt);

    printf("Time(sec) : %d\n",(int)tt);


    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("Time(sec): %d\n",(int)tv.tv_sec);
    printf("Time(micro-sec_ : %d\n",(int)tv.tv_usec);

    return 0;
}

