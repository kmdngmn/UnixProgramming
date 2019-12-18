#include <stdio.h>
#include <time.h>

int main(void){
    tzset();

    extern char *tzname[2];
    extern long timezone;
    extern int daylight;

    printf("Timezone : %d\n",(int)timezone);
    printf("Daylight : %d\n",daylight);
    printf("TZname[0] : %s\n", tzname[0]);
    printf("TZname[1] : %s\n", tzname[1]);

    struct tm *tm;
    time_t t;

    tm = localtime(&t);
    printf("Y:%d M:%d D:%d\n",tm->tm_year,tm->tm_mon, tm->tm_mday);

    return 0;
}

