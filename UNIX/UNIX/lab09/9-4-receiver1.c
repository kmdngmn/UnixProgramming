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

    key = ftok("msgfile",1);
    if((msgid = msgget(key, 0)) < 0){
        perror("msgget");
        exit(1);
    }
    
    len = msgrcv(msgid, &inmsg, 80, 1, 0); // msgtype : 1 -> print mtype : 1
    printf("Received Msg = %s", inmsg.mtext);
    
    return 0;
}

