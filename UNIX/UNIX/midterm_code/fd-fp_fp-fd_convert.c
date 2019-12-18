#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){

    FILE *fp;
    int fd;
    char buf[BUFSIZ];
    

    fd = open("unix.txt",O_RDONLY);

    fp = fdopen(fd,"r"); // file descriptor -> file pointer

    
    fread(buf,sizeof(char)*2,sizeof(buf),fp);
    printf("%s\n",buf);
    

    rewind(fp); // offset -> 0

    fd = fileno(fp); // file pointer -> file descriptor

    read(fd,buf,sizeof(buf));
    printf("%s\n",buf);

    close(fd);
    fclose(fp);

    return 0;
}
