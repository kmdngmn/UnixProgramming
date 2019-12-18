#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){   // argv[1] : process number  ex)./filename 2445
    key_t key;
    int shmid;
    void *shmaddr;
    char buf[1024];

    key = ftok("shmfile", 1);
    shmid = shmget(key, 1024, 0);

    shmaddr = shmat(shmid, NULL, 0);
    strcpy(shmaddr, "Hello, I'm talker\n");

    kill(atoi(argv[1]), SIGUSR1);
    sleep(2);
    strcpy(buf,shmaddr);

    printf("Listener said : %s\n", buf);
    system("ipcs -m");
    shmdt(shmaddr);
    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}

