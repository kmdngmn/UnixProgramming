#include <unistd.h>
#include <stdio.h>

int main(void){

    char *cwd;
    char wd[BUFSIZ];

    cwd = getcwd(NULL, BUFSIZ);
    printf("current working directory : %s\n",cwd);

    //chdir("hanbit"); // cd hanbit

    return 0;
}
