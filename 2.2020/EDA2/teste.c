#include <stdio.h>

#define MAXIMO_DE_BOTAS 100000
#define TAMANHOS_DE_PE  500000

typedef struct TipoBota
{
    int     tamanho;
    char    lado;
}TipoBota;

int main()
{
    int N,i;
    TipoBota vetorBotas[MAXIMO_DE_BOTAS];

    while(scanf("%d %c", &vetorBotas[i].tamanho, &vetorBotas[i].lado) != EOF){
        N++;
        i++;
    }
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = i + 1 ; j < N ; j++)
        {
            if(vetorBotas[i].tamanho >
                vetorBotas[j].tamanho)
            {
                TipoBota aux;
                aux.tamanho = vetorBotas[i].tamanho;
                aux.lado    = vetorBotas[i].lado;

                vetorBotas[i].tamanho   = vetorBotas[j].tamanho;
                vetorBotas[i].lado      = vetorBotas[j].lado;

                vetorBotas[j].tamanho   = aux.tamanho;
                vetorBotas[j].lado      = aux.lado;
            }
        }
    }
    int botasEsquerdas[TAMANHOS_DE_PE] = { 0 };
    int botasDireitas[TAMANHOS_DE_PE] = { 0 };

    for(int i = 0 ; i < N ; i++)
    {
        int tamanhoDoPeAnalisado    = vetorBotas[i].tamanho;
        int ladoDoPeAnalisado       = vetorBotas[i].lado;

        if(ladoDoPeAnalisado == 'E')
        {
            botasEsquerdas[tamanhoDoPeAnalisado]++;
        }else if(ladoDoPeAnalisado == 'D')
        {
            botasDireitas[tamanhoDoPeAnalisado]++;
        }
    }
    int total = 0;
    for(int i = 11000 ; i <= 22000; i++)
    {
        if(botasEsquerdas[i] == botasDireitas[i])
        {
            total += botasEsquerdas[i];
        }else if(botasEsquerdas[i] < botasDireitas[i])
        {
            total += botasEsquerdas[i];
        }else
            total += botasDireitas[i];
    }
    printf("%d \n", total);

    return 0;
}