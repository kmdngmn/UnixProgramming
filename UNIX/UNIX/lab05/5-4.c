#include <time.h>
#include <stdio.h>
#include <sys/times.h>

char *output[] = {
    "%G. %m. %d. (%a) %H:%M:%S %Z" // G:year, m:month, d:date, a:day of the week, H:hour, M:minute, S:sec, Z: time zone KST 
};

int main(void){

    struct tm *tm;
    time_t t;
    int n;
    char buf[257];

    time(&t);
    tm = localtime(&t); // time information in seconds

    for(n=0;n<3;n++){
        strftime(buf,sizeof(buf),output[n],tm); // strftime : output form
        printf("%s\n",buf); 
    }

    return 0; 
}
