#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>

struct mymsgbuf{
    long mtype;
    char mtext[80];
};

int main(void){
    struct mymsgbuf inmsg;

    key_t key;
    int msgid, len;

    key = ftok("keyfile", 1); // create same key
    if((msgid = msgget(key,0)) < 0){
        perror("msgget");
        exit(1);
    }

    len = msgrcv(msgid, &inmsg, 80,0,0);
    printf("Received Msg = %s, Len=%d\n", inmsg.mtext, len);

    return 0;
}
