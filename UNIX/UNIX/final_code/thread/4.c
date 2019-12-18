#include <stdio.h>
#include <pthread.h>

#define NUMLOOP 100000000

unsigned int cnt = 0;
pthread_mutex_t mutex;

void *count(void * data){
    int i;
    for(i = 0; i < NUMLOOP; i++){

        pthread_mutex_lock(&mutex);
        cnt++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main(void){

    pthread_mutex_init(&mutex, NULL);
    pthread_t t[2];
    pthread_create(&t[0], NULL, count, NULL);
    pthread_create(&t[1], NULL, count, NULL);

    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);

    printf("%u\n",cnt);
    pthread_mutex_destroy(&mutex);

    return 0;
}

