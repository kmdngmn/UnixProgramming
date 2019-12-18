#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){

    struct passwd *pw;
    int n;

    while((pw=getpwent()) != NULL){
        
        printf("UID : %d, LoginName : %s\n", (int)pw->pw_uid, pw->pw_name);

    }

    return 0;
}

