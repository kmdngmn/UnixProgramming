#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void){
    struct stat buf;

    stat("password.txt", &buf);
    printf("mode before change = %o\n", (unsigned int)buf.st_mode);

    buf.st_mode |= S_IWGRP; // add mode write permission in Group
    buf.st_mode &= ~(S_IROTH); // remove mode read permission in Other

    chmod("password.txt", buf.st_mode);

    stat("password.txt",&buf);

    printf("mode after change = %o\n", (unsigned int)buf.st_mode);

    return 0;
}
