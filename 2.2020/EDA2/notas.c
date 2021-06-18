#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define N (300000)

int table[N];

int main(){

    memset(table,0,sizeof(table));

    int numAlunos, notas;
    scanf("%d", &numAlunos);

    int max_nota = 0;

    for(int i = 0; i < numAlunos; i++){
        if(i==0)
            max_nota = notas;
        
        scanf("%d", &notas);
        table[notas]++;
        
        if (table[max_nota] < table[notas]){
            max_nota = notas;
        }
        else if (table[max_nota] == table[notas]){
            if (notas > max_nota)
                max_nota = notas;
        }
    }
        printf("%d\n", max_nota);
    return 0;
}

    // while(scanf("%d", &n) && n !=0){
    //     int max_pos = 0;￼

    //     for(int i = 0; i<n; i++){            
    //         if(i==0)
    //             max_pos = value;

    //         scanf("%d", &value);
    //         table[value]++;
    //         printf("%d",value);

    //         if(table[max_pos] < table[value])
    //             max_pos = value;
    //     }
    //     printf("%d\n", max_pos);
    // }
//     return 0;
// }