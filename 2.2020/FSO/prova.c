#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAXRANDOM 100000

void leiaEntradas(){
    int modulo;
    int ocorrencias;
    (scanf("%d", &modulo) && scanf("%d",&ocorrencias));
    return modulo, ocorrencias;
}





void calcula_perguntas(unsigned int s)
{
    int v[MAXRANDOM];
    for(int i=0;i<MAXRANDOM;i++)
        v[i]=rand_r(&s);
    int mi,bi;

    while(ESPERA(mi,bi))
    {
        conta=0;
        for(int i=0;i<MAXRANDOM;i++)
            if(v[i]%mi==bi)
                conta++;
        sem_wait(&sem);
        somaglobal+=conta;
        sem_post(&sem);
    }
}

int main(void)
{   

    int semente1,sememte2;
    scanf("%d","%d",&semente1,&semente2);

    while(leiaEntradas() == 1){
        
    }

    pthread_t tid[2];

    pthread_create(&tid[0],NULL,calcula_perguntas,&semente1);
    pthread_create(&tid[1],NULL,calcula_perguntas,&semente2);

    cria_thread(calcula_perguntas,semente1);
    cria_thread(calcula_perguntas,s2);
    
    while(leia(mi,bi))
    {
        LIBERATHREADS;
        AGUARDECALCULOTHREADS;
        printf("%d\n",somaglobal);
    }
}