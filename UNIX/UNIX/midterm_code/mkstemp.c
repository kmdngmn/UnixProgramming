#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(void){

    int fd;
    char buf[] = "/tempXXXXXX"; //template - random string    
    
    char str[]="UNIX";

    fd = open("mkstemp.txt",O_CREAT | O_EXCL | O_TRUNC | O_WRONLY,0644);

    fd = mkstemp(buf);

    write(fd,str,sizeof(str)-1);
    close(fd);

    return 0;
}

