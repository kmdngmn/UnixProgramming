#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/shm.h>

int main(void){

    key_t key;
    int shmid;
    char *shmaddr;
    char buf[1024];

    key=ftok("shmfile", 1);
    shmid = shmget(key,1024,0);

    shmaddr = shmat(shmid, NULL, 0);
    strcpy(buf,shmaddr);
    printf("%s\n",buf);

    shmdt(shmaddr);
    shmctl(shmid,IPC_RMID, NULL);

    return 0;
}

