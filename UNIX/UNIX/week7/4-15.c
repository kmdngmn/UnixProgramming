#include <utmpx.h>
#include <stdio.h>

int main(void){
    struct utmpx *utx;
    printf("LoginName Line\n");
    printf("---------------\n");

    while((utx=getutxent()) != NULL){
        printf("%s   %s\n", utx->ut_user,utx->ut_line);
    }

    return 0;
}

