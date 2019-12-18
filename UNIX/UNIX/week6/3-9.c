#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{

    symlink("unix.txt", "unix.sym");

    return 0;
}

