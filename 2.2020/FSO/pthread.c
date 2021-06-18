#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *funcao(void *a){
    printf("SOU uma THread\n");
    while(1);
}

int main(void){
    pthread_t tid;
    pthread_create(&tid,NULL,&funcao,NULL);
    printf("thread criada\n");
    printf("Thread principal dormindo um pouco.\n");
    sleep(10);
    printf("Thread principal consumindo um pouco de CPU.\n");
    for(int i = 0; i< 100000000; i++){
        getpid();
    }
    printf("Thread principal dormindo um pouco.\n");
    sleep(10);
    printf("tchau\n");
    return 0;
}