#include <stdio.h>
#include <stdlib.h>


int separa(Item *v, int l, int r){
    int tam = r-l+1;
    int cpos;

    int Item c = v[r];

    Item *menores = malloc(sizeof(Item)*tam);
    Item *maiores = malloc(sizeof(Item)*tam);

    int imenores = 0, imaiores = 0;

    for(int i = l; i<r;i++){
        if(less(v[i],c))menores[imenores++] = v[i];
        else maiores[imaiores++]= v[i];
    }

    int i = l;
    for(int j = 0; j<imenores; j++){
        v[i++] = menores[j];
    }
    v[i] = c;
    cpos = i;
    i++;
    for(int j=0; j<imaiores; j++)
        v[i++] = maiores[j];

    free(maiores);
    free(menores);
    return cpos;
}




int main(){

}

int separa(Item *v, int l, int r){
    Item c = v[r];
    int j = l;
    for(int k = l; k< r; k++){
        if(less(v[k],c))
        exch(v[k],v[j]);
        j++;
    }
    exch(v[j],v[r]);
    return j;
}