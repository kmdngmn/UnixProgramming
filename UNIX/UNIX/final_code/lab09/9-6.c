#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

int main(void){
    key_t key;
    int shmid;

    char buf[BUFSIZ];

    char *shmaddr;

    key = ftok("shmfile", 1);
    shmid = shmget(key, 1024, 0);
    shmaddr = shmat(shmid, NULL,0);

    strcpy(buf,shmaddr);

//    printf("shared memory message : %s\n",buf);

    write(1,buf,19);
    write(1,"\n",1);

    shmdt((char *)shmaddr);

    return 0;
}

