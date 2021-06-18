#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nvoos[101];

int main()
{
    int aeroportos;
    int voos;
    int x, y, max, i = 0;
    int teste = 1;
    
    while (scanf("%d %d", &aeroportos, &voos) == 2 && aeroportos > 0){
        memset(nvoos, 0, sizeof(nvoos));
        while (voos-- > 0){
            scanf("%d %d", &x, &y);
            nvoos[x]++;
            nvoos[y]++;
        }
        max = nvoos[1];
        for (i = 2; i <= aeroportos; i++){
            if (nvoos[i] > max)
                max = nvoos[i];
        }
        printf("Teste %d\n", teste++);
        for (i = 1; i <= aeroportos; i++){
            if (nvoos[i] == max)
                printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}