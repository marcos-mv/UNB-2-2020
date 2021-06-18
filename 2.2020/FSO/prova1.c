#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXRANDOM 100000

int main(void)
{   
    int pseudo1[MAXRANDOM];
    int pseudo2[MAXRANDOM];

    int semente1 = 0, semente2=0;
    int modulo =0, ocorrencias=0;    
    
    scanf("%d",&semente1);
    scanf("%d",&semente2);

    for(int i= 0; i<MAXRANDOM; i++){
        pseudo1[i]=rand_r(&semente1);
        pseudo2[i]=rand_r(&semente2);        
    }

    while((scanf("%d", &modulo) && scanf("%d",&ocorrencias) == 1)){

        int soma = 0;
        int contador1=0, contador2=0;
        
        for(int i= 0; i<MAXRANDOM; i++){
            if((pseudo1[i]%modulo) == ocorrencias){
                contador1++;
            }
            if((pseudo2[i]%modulo) == ocorrencias){
                contador2++;
            }            
        }
        soma = contador1+contador2;
        printf("%d\n", soma);
    }

    return 0;
}