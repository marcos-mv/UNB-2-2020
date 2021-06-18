#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char nome[4];
int count=0, i=0, j=0, k=0;

    while(scanf("%s", nome)!= EOF){
        // printf("%s ",nome);
        k++;
        if(nome[0] == 's'){
            count ++;
        }

        if (count >= 2 && k == 10){
            i++;
            count = 0;
        }
        if (k == 10){
            k = 0;
            count = 0;
        }
        // printf("%d %d\n",count, k);
    }

    printf("%d\n", i);

    return 0;
}