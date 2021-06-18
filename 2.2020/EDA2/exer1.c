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

    void imprimeheep(){
        if(PQempty)
    }



    return 0;
}