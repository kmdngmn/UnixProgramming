#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int g = 10;

void *tfunction(void *data){
    int d = *(int *)data;
    int tid = (int)pthread_self();
    int p = (int)getpid();

    printf("Hello! I'm thread %u of %d, %d is passed from main\n", tid,p,d);
    printf("global variable is %d\n", ++g);
    pthread_exit(NULL);
}

int main(void){
    pthread_t t1,t2;
    int rcc, t = 1;

    printf("In main: creating thread t1\n");
    pthread_create(&t1,NULL,tfunction,(void *)&t);
    sleep(1);
    t++;

    printf("In main: creating thread t2\n");
    pthread_create(&t2, NULL, tfunction, (void *)&t);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}

