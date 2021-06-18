#include<stdio.h>

int main(){

    int k=0, i=0, j=0, tamanho[100000], qtd=0;
    char lado[100000];

    while( scanf("%d %c", &tamanho[i], &lado[i])!= EOF){
        k++;
        i++;
    }

    for(i = 0; i < k; i++){
        scanf("%d %c", &tamanho[i], &lado[i]);
    }

    for(i = 0; i< k; i++){
        for(j = 0; j < k; j++){
            if(tamanho[i] == tamanho[j]){
                if(lado[i] == lado[j]){
                    qtd++;
                }
            }
        }
    }

    printf("%d\n", qtd/2); 

    return 0;
} 