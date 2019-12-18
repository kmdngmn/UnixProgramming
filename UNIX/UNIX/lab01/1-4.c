#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // library for exit(1)
#include <errno.h>
#include <string.h> // library for strerror

extern int errno;

int main(void)
{

    char *str;

    if(access("linus.txt", F_OK) == -1) { // if linux.txt file is existed
        str = strerror(errno); // error is stored at str(variable)
        printf("linux.txt: %s\n", str);
        exit(1); // system call
    }
        return 0;
}

