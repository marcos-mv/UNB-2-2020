void fixUp(Item *v, int k){
    while(k>1 && less(v[k/2],v[k])){
        exch(v[k],v[k/2]);
        k = k/2;
    }
}

void fixDown(Item *v, int k){
    int j;
    while(2*k <= N){
        j = 2*k;
        if(j<N && less(v[j],v[j+1])){
            j++;
        }
        if(!less(v[k],v[j])){
            break;
        }
        exch((v[k],v[j]));
        k = j;
    }
}

static Item *pq;
static int N;

void PQinit(int maxN){
    pq = malloc(sizeof(Item)*(max N +1));
    N =0;
}

int PQempty(){
    return N == 0;
}

void PQinsert(struct pq_st *PQ, Item novo){
    PQ -> pq[++PQ->N] = novo;
    fixUP(PQ->pq,PQ->N);
}

Item PQdelMax(struct pq_st *PQ)
{
    exch(PQ->pq[1],PQ->pq[PQ->N]);
    fixDown(PQ->pq,1,--PQ->N);
    return PQ->pq[PQ->N+1];
}

// fila de prioridade baseada em indice

Item *data; <- gerado fora da fila de prioridade e possui os elementos que estão sendo manipulados pelo programa.

Possui definição das funções 'less'que sabem comparar os elementos do tipo Item.

no lado da fila de prioridade, temos

struct pq_ist{
    int N;
    int *pq;    //fila de prioridades,armazena os indices de um conjunto item
    int *qp;    // mantem a posicao de heap para o elemento de indice k do conjunto item. funciona como uma hash
}

void PQinit(struct pq_ist *PQ, int MAX){
    PQ -> N = MAX;
    PQ -> pq = malloc(sizeof(int)*(MAX +1));
    PQ -> qp = malloc(sizeof(int)*(MAX+1));
}

int PQempty(struct pq_ist *PQ)
{
    return !PQ->N;
}

void PQinsert(struct pq_ist *PQ, int K){
    PQ -> qp[k]= ++PQ->N;
    PQ -> pq[PQ->N] = k;
    fixUP(PQ-> pq , PQ->N);
}

void exch(int i, int j){
    int t;
    t = qp[i];
    qp[i] = qp[j];
    qp[j]=t;
    pq[qp[i]]=i;
    pq[qp[j]]=j;
}

void PQchange(struct pq_st *PQ, int k){

    fixUP(PQ -> pq, qp[k]);
    fixDown(PQ -> pq, qp[k], PQ-> N);

}

k   /qp[k]  pq[k]        /item Data
0   /                    / Bruno 100
1   /      2          /Kleidson 90
2   /1      4         /Eliseu 93
3   /                       /João 97
4   /2                     /Ivan 74

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 5;

    printf("%ls",a);
    return 0;
}

//imprimir os 100 menores numeros de um conunto de 10⁶(1kk) de numeros.

int main(){

    PQinit(101);

    for(int i = 0; i< 100; i++){
        int x;
        scanf("%d",&x);
        PQinsert(x);
    }

    while(scanf("%d",&x)==1){
        PQinsert(x);            //nesse ponto temos 101 elementos no PQ
        PQdelmax(x);
    }

    //ou

    ITEM PQespia max(){
        return pq[1];
    }

    void PQworkaroundMax(){
        pq[1] = x;
        fixdown(pq,1,N);
    }

    while(scanf("%d",&x)==1){
        if(x< PQespiamax()){
            PQinsert(x);            //nesse ponto temos 101 elementos no PQ
            PQdelmax(x);
            continue;               //salto não condicional
        }
    }

    //solucao do Hugo
    sort(pq,1,100);
    for(int i=1; i<101; i++){
        printf("%d", pq[1]);
    }

    // solução joao Pedro

    void imprimeheap(){
        if(PQempty(1)return;
        int x = PQdelMax();
        imprimeheap();
        printf("%d",x);
    }



    return 0;
}