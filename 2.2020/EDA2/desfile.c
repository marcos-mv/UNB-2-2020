#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define N (10000000+100)

int table[N];

int main(){

    memset(table,-1,sizeof(table));

    int n,value;

    while(scanf("%d", &n) && n !=0){
        int max_pos = 0;

        for(int i = 0; i<n; i++){            
            if(i==0)
                max_pos = value;

            scanf("%d", &value);
            table[value]++;

            if(table[max_pos] < table[value])
                max_pos = value;
        }
        printf("%d\n", max_pos);
    }
    return 0;
}