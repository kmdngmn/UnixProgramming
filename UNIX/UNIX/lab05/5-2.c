#include <stdio.h>
#include <pwd.h>
#include <unistd.h>

int main(void){

    struct passwd *pw;
 
    for(int i = 0; i < 3; i++){
        pw = getpwent();
        printf("UID : %d, *pw_dir : %s, *pw_shell : %s\n",(int)pw->pw_uid, pw->pw_dir, pw->pw_shell);
    }

    return 0;
}

