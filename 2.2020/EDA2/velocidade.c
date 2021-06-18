#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// int cmpfunc (const void * a, const void * b) {
//    return ( *(int*)a - *(int*)b );
// }

struct velocidade{
    int dowRepr;
    int upRepr;
};


int cmpfunc(const void *a, const void *b){
    if((*(struct velocidade*)a).dowRepr == (*(struct velocidade*)b).dowRepr){
        if ((*(struct velocidade*)a).upRepr > (*(struct velocidade*)b).upRepr)
        return 1;
        else
            return 0;
    }
    else{
        if((*(struct velocidade*)a).dowRepr < (*(struct velocidade*)b).dowRepr){
            return -1;
        }
        else
            return 1;
    }
}

int main(){

    int download, upload, numMed=0;

    float newlimiar, limiar;

    scanf("%d %d %f %d", &download, &upload, &limiar, &numMed);

    int medDow[numMed], medUp[numMed];

    struct velocidade item[numMed];

    char barra;

    newlimiar = (100 - limiar)/100;

    int count=0;

    for(int i = 0; i< numMed; i++){
        scanf("%d%c%d", &medDow[i],&barra, &medUp[i]);

        if(medDow[i] < floor(download * newlimiar) || medUp[i] < floor(upload * newlimiar)){
            item[count].dowRepr = medDow[i];
            item[count].upRepr = medUp[i];
            count++;
        }
    }

    qsort(item, count, sizeof(struct velocidade), cmpfunc);    

    // for(int j =0; j<count; j++){
    //     printf("%d/%d\n", item->dowRepr[j], item->upRepr[j]);
    // }

    for(int j =0; j<count; j++){
        printf("%d/%d\n", item[j].dowRepr, item[j].upRepr);
    }

    return 0;
}