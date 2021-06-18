#include <stdio.h>
#include <stdlib.h>

int main(){

    int numeroVetor =0;
    scanf("%d", &numeroVetor);
    int dados[numeroVetor];
    int i =0, j=0;
    int testes[numeroVetor];

    while(i<numeroVetor){
        scanf("%d", &dados[i]);
        i++;
    }

    while(scanf("%d",&testes[j]) != EOF){
        for(int l=0; l<testes[j]; l++){
            printf("%d  %d\n",dados[l], j); 
        }
        j++;
    }

    // for(int l=0; l<testes[])

    // for(int k=0; k < j; k++){
    //     printf("%d %d\n",testes[k], k);
    // }

    return 0;
}