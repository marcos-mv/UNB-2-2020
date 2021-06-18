#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int tamanho;
    char lado;
}TipoBota;

int main(){

    TipoBota botas[100000];
    int i=0, j=0, qtd=0;
    char lado[100000];
    
    while(scanf("%d %c", &botas[i].tamanho, &botas[i].lado) != EOF){

        printf("%d %c\n",botas[i].tamanho,botas[i].lado);
        i++;
    }
    printf("%d\n",i);

    for(int l=0; l<i; l++){
        for(int m = l+1; m<i; m++ ){
            if(botas[l].tamanho > botas[m].tamanho){
                TipoBota temp;
                temp.tamanho = botas[l].tamanho;
                temp.lado = botas[l].lado;

                botas[l].tamanho = botas[m].tamanho;
                botas[l].lado = botas[m].lado;

                botas[m].tamanho = temp.tamanho;
                botas[m].lado = temp.lado;
            }
        }
    }

    int botasE[100000];
    int botasD[100000];

    for(int p =0; p<i; p++){
        int tamanho = botas[p].tamanho;
        int lado = botas[p].lado;

        if( lado == 'E'){
            botasE[tamanho]++;
        }else if(lado == 'D'){
            botasD[tamanho]++;
        }
    }

    int total;

    for (int a = 0; a < i; a++){
        if(botasE[a] == botasD[a]){
            total += botasE[a];
        }else if(botasE[a]< botasD[a]){
            total += botasE[a];
        }else
        total += botasD[a];

    }

    printf("%d\n", total);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// # define N (10000000+100)

// int tamanho[N], lado[N];

// int main(){

//     memset(tamanho,-1,sizeof(tamanho));
//     memset(lado,-1,sizeof(lado));

//     int i = 0
//     int n,value;

//     while(scanf("%d %c", &tamanho[i], &lado[i]) && n !=0){
//         int max_pos = 0;

//         for(int i = 0; i<n; i++){            
//             if(i==0)
//                 max_pos = value;

//             scanf("%d", &value);
//             table[value]++;

//             if(table[max_pos] < table[value])
//                 max_pos = value;
//         }
//         printf("%d\n", max_pos);
//     }
//     return 0;
// }