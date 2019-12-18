#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void){
    struct stat buf;

    stat("password.txt", &buf);

    printf("Mode = %o (hexadecimal: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

    if(S_ISFIFO(buf.st_mode)) printf("password.txt: FIFO\n");
    if(S_ISDIR(buf.st_mode)) printf("password.txt: Directory\n");
    if(S_ISREG(buf.st_mode)) printf("password.txt: Regular File\n");

    return 0;
}
