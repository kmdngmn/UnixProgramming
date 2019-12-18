#include <unistd.h> // library for F_OK
#include <stdio.h>
#include <errno.h>

extern int errno; // use global variable errno from other file

int main(void)
{
    if (access("unix.txt", F_OK) == -1) { // if unix.txt file is existed
        printf("errno=%d\n", errno); // print errno
    }

    return 0; // return (success ? 0: -1)
} 

