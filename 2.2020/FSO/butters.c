#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


int main(){
    int semente = 1, x, Mi,Mf;

    scanf("%d",&Mi);
    scanf("%d",&Mf);


    for(int j = 0; j<5; j++){

        for(int i =0 ; i < 10000; i++){
            x = rand_r(&semente);
        }
        printf("%d\n", x%256);
    }


}