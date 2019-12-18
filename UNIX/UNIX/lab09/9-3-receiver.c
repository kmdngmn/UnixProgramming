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
    int i;

    key = ftok("msgfile",1);
    if((msgid = msgget(key, 0)) < 0){
        perror("msgget");
        exit(1);
    }

    for(i = 0; i<10; i++){
        len = msgrcv(msgid, &inmsg, 80, 0, 0);
        printf("Received Msg = %s", inmsg.mtext);
    //    write(1,inmsg.mtext,80); // stdout?
    }

    return 0;
}

