#include <stdio.h>
#include <stdlib.h>

struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};


int cmpfunc(const void *a, const void *b){
    if((*(struct aluno*)a).matricula == (*(struct aluno*)b).matricula){
        return 0;
    }
    else{
        if((*(struct aluno*)a).matricula < (*(struct aluno*)b).matricula){
            return -1;
        }
        else
            return 1;
    }
}

int main(){
    int i;
    struct aluno V[4] = {{2,"andre",9.5,7.0,8.5},
                        {4,"Ricardo",9.5,7.0,8.5},
                        {1,"Ana",9.5,7.0,8.6},
                        {3,"Júlia",9.5,7.0,8.5}};
    
    qsort(V,4,sizeof(struct aluno),cmpfunc);

    for(i = 0; i< 4; i++){
        printf("%d) %s\n",V[i].matricula,V[i].nome);
    }
    return 0;
}