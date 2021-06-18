#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAXRANDOM 100000

int semente1=0, semente2=0;
int modulo=0, ocorrencias=0;
int somaglobal = 0;
sem_t semaforo;
int pseudo[MAXRANDOM];

void calcula_perguntas(unsigned int s)
{
    memset(pseudo,0,sizeof(pseudo));
    int pseudo[MAXRANDOM];
    int conta = 0;
    for(int i=0;i<MAXRANDOM;i++) {
        printf("pseudoi %d", pseudo[i]);
        pseudo[i]=rand_r(&s);
    }

    conta = 0;

    for(int i=0;i<MAXRANDOM;i++){
        if(pseudo[i]%modulo==ocorrencias)
            conta++;
	}
	sem_wait(&semaforo);
        somaglobal+=conta;
        sem_post(&semaforo);
    
}

int main(void)
{
    pthread_t tid[2];
    sem_init(&semaforo,0,1);

    scanf("%d",&semente1);
    scanf("%d",&semente2);
    
    while((scanf("%d", &modulo) && scanf("%d",&ocorrencias) == 1)){

    pthread_create(&tid[0], NULL, &calcula_perguntas,&semente1-1);
    pthread_create(&tid[1], NULL, &calcula_perguntas,&semente2-1);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
    printf("%d\n",somaglobal);
	somaglobal = 0;
    }

    return 0;
}
