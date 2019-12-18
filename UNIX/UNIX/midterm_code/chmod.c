#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void){

    struct stat buf;

    system("ls -l unix.txt");

    chmod("unix.txt", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH);
    stat("unix.txt",&buf);

    printf("mode : %o\n",(unsigned int)buf.st_mode);

    system("ls -l unix.txt");

    buf.st_mode |= S_IWGRP;
    buf.st_mode &= ~(S_IROTH);

    chmod("unix.txt",buf.st_mode);

    system("ls -l unix.txt");

    stat("unix.txt",&buf);
    printf("mode : %o\n",(unsigned int)buf.st_mode);

    return 0;
}

