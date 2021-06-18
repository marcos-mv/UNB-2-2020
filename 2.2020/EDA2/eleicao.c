#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 11

int hash1(int value){
    return value%N;
}

int hash2(int value){
    return(value%N + (value*value)%N) %N;
}

int hashtable[N];

void insert(int value){
    int pos = hash1(value);

    if (hashtable[pos] == -1){
        hashtable[pos] = value;
        printf("Inseriu %d em %d usando hash1\n", value, pos);
    }
    else{
        for(int i = 0; i<10; i++){
            pos = hash2(pos);
            if(hashtable[pos]== -1){
                hashtable[pos] = value;
                printf("Inseriu %d em %d usando hash2\n", value, pos);
                break;
            }
        }
    }
}

int main(){

    int n;

    scanf("%d", &n);
    memset(hashtable,-1,sizeof(int)*N);

    int value;

    for(int i=0; i<n; i++){
        scanf("%d", &value);
        insert(value);
    }
    return 0;
}