#include <stdio.h>
#include <pwd.h>
#include <unistd.h>

int main(void){

    struct passwd *pw;

    pw = getpwuid(getuid());

    printf("uid : %d, ",(int)pw->pw_uid);
    printf("name : %s\n",pw->pw_name);

    pw = getpwnam("ubuntu");

    printf("uid : %d, ", (int)pw->pw_uid);
    printf("dir : %s\n",pw->pw_dir);


    return 0;
}
