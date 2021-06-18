#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define N (1000000+20)
int table[N];
int main(){

    memset(table,0,sizeof(table));

    int n,value;

    while(scanf("%d", &n) && n !=0){
        for(int i = 0; i <n; i++){
            scanf("%d", &value);
            table[value]++;
        }
        int max_pos = 0;

        for(int i = 0; i<N; i++){
            if(table[i] > table[max_pos])
                max_pos = i;
        }

        printf("%d\n", max_pos);
    }
    return 0;
}