#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){    
    int a;
    int b;
    int placa[100];
    int i = 0;
    int numPlacas;

    while(scanf("%d %d", &a, &b)!= EOF){

        // printf("%d %d \n", a,b);
        if(a == 1){
            if(i < 100){
                placa[i] = b;
                i++;
                qsort(placa, i, sizeof(int), cmpfunc);
                // printf("%d\n",placa[i]);
            }
            else{
                if(b < placa[i-1]){
                    placa[i-1] = b;
                    qsort(placa, i, sizeof(int), cmpfunc);
                }
            }
        }
        else if( a == 2){
            //printf("%d", a);
            for(int l = 0; l < b; l++){
                printf("%d ", placa[l]);
            }
            printf("\n");
        }
    }
    return 0;
}
