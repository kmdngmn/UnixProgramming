#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/msg.h>

struct mymsgbuf{
    long mtype;
    char mtext[80];
};

int main(void){
    struct mymsgbuf inmsg;
    key_t key;
    int msgid, len;

    key = ftok("msgfile", 1);
    msgid = msgget(key,0);

    for(int i = 0; i < 10; i++){

        len = msgrcv(msgid, &inmsg, 80, 0,0);
   
        printf("Received Msg = %s",inmsg.mtext);
    }
    return 0;
}

