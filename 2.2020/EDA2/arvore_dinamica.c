#include <stdio.h>
#include <stdlib.h>


type struct NO* ArvBin;{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz == NULL){
        *raiz = NULL;
    }
    return raiz;
}
void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL)
        return 1;
    return 0;
}

int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    
    int alt_esq = altura_ArvBin(&((*raiz) -> esq));
    int alt_dir = altura_ArvBin(&((*raiz) -> dir));

    if(alt_esq > alt_dir){
        return (alt_esq+1);
    }
    else{
        return(alt_dir +1);
    }
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL){
        return 0;
    }
    if(*raiz ==NULL){
        return 0;
    }
    int alt_esq = totalNO_ArvBin(&((*raiz) -> esq));
    int alt_dir = totalNO_ArvBin(&((*raiz) -> dir));
    return(alt_esq + alt_dir +1);
}

// Pré-ordem : visita a raiz, o filho da esquerda e o filho da direita.
// EM-ordem: visita o filho da esquerda , a raiz, e o filho da raiz.
// Pos-ordem: visita o filho da esquerda, o filho da direta e a raiz.

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)-> esq));
        preOrdem_ArvBin(&((*raiz)-> dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->esq);
        preOrdem_ArvBin(&((*raiz)-> info));
        preOrdem_ArvBin(&((*raiz)-> dir));
    }
}
void posOrdem_ArvBin(ArvBin *raiz){            //pos ordem melhor pq garante que vc acessa os filhos antes de matar o pai
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->esq);
        preOrdem_ArvBin(&((*raiz)-> dir));
        preOrdem_ArvBin(&((*raiz)-> info));
    }
}

int insere_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* novo;
    
    novo = (struct NO*) malloc(sizeof(struct NO));
    
    if(novo == NULL){
        return 0;
    }
    novo->info =valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL){
        *raiz = novo;
    }
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;

        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;               //elemento já existe
            }
            if(valor > atual->info){
                atual = atual->dir;
            }
            else{
                atual = atual -> esq;
            }
        }
        if(valor > ant-> info){
            ant -> dir = novo;
        }
        else{
            ant -> esq = novo;
        }
    }
    return 1;
}

int remove_ArvBin(ArvBin *raiz, int valor){     //busca do nó a ser removido
    if(raiz == NULL){
        return 0;
    }
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    
    while(atual != NULL){
        if (valor == atual -> info){
            if(atual == *raiz){
                *raiz = remove_atual(atual);
            }
            else{
                if(ant->dir == atual){
                    ant->dir = remove_atual(atual);
                }
                else{
                    ant->esq = remove_atual(atual);
                }
            }
            return 1;
        }
        ant = atual;

        if(valor > atual->info){
            atual = atual -> dir;
        }
        else{
            atual = atual ->esq;
        }
    }
    
}

struct NO* remove_atual(struct NO* atual){       //trata os 3 tipos de remocao

    struct NO *no1, *no2;

    if(atual -> esq == NULL){                   //sem filho da esquerda aponta para o filho da direita
        no2 = atual->dir;                        //(trata nó folha e nó com um filho).
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;

    while(no2->dir != NULL){                    //procura filho mais a direita na subarvore da esquerda
        no1 = no2;
        no2 = no2->dir;
    }

    if(no1 != atual){                           //copia o filho mais a direita na sub-arvore esquerda
        no1->dir = no2 ->esq;                   // para o lugar do nó removido
        no2-> esq = atual->esq;
    }
    no2->dir = atual -> dir;
    free(atual);
    return no2;
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if (raiz == NULL){
        return 0;
    }
    struct NO* atual = *raiz;

    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual -> info)
            atual = atual ->dir;
        else
            atual = atual ->esq;
    }
    return 0;
}


int main(){

    ArvBin* raiz;

    int x = estaVazia_ArvBin(raiz);
    if(estaVazia_ArvBin(raiz))      //formas de verificar se a arvore esta vazia

    int y = altura_ArvBin(raiz);   //forma de chamar e verificar a altura da arvore

    int z = totalNO_ArvBin(raiz);   // total de nos na arvore

    preOrdem_ArvBin(raiz);

    emOrdem_ArvBin(raiz);

    posOrdem_ArvBin(raiz);

    int a = insere_ArvBin(raiz,valor);

    int b = remove_ArvBin(raiz,valor);

    int c = consulta_ArvBin(raiz, valor);

    return 0;
}