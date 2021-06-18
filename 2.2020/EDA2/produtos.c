#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getDados(){
    int numProd;
    scanf("%d", &numProd);
    return numProd;
}

void Quick(int vetor[getDados()], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   

}

int main(){

    int numProd = getDados();
    int pag, prodPorPag;
    scanf("%d", &pag);
    scanf("%d", &prodPorPag);
    
    printf("numero de produtos %d\n",numProd);
    printf("numero da paginas %d\n",pag);
    printf("produtos por pagina %d\n",prodPorPag);

    int prod[numProd];

    int i; 

    memset(prod,0,sizeof(prod));

    for(i = 0; i <numProd; i++){
        scanf("%d", &prod[i]);
    }

    printf("\n");   

    Quick(prod, 0, numProd);
    // if (prodPorPag*pag < numProd)
        for(int j=0; j<prodPorPag; j++){
            printf("%d\n",prod[j+((pag)*prodPorPag)]);
        }
    // else{
            int total = numProd;

    //     for(int j=0; j<prodPorPag; j++){
    //         printf("%d\n",prod[j+((pag)*prodPorPag)]);
    //     }
    // }

    printf("\n");

    for(i = 0; i < numProd; i++){
        printf("%d\n", prod[i]);
    }
    printf("\n");
    return 0;   
}

