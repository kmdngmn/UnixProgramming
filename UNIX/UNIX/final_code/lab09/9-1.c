#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <string.h>

struct mymsgbuf{
    long mtype;
    char mtext[80];
};

int main(void){
    key_t key;
    int msgid;
    struct mymsgbuf mesg;

    key = ftok("msgfile", 1);
    msgid = msgget(key,IPC_CREAT|0644);

    mesg.mtype = 1;
    strcpy(mesg.mtext, "my message\n");

    msgsnd(msgid, (void *)&mesg, 80, IPC_NOWAIT);

    return 0;
}


