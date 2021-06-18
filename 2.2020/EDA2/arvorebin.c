#include <stdio.h>
#include <stdlib.h>



typedef struct node* link;
struct node {
    Item item; 
    link esq;
    link dir;
};

void tranverse(link h){
    if (h==NULL)
        return n;
    printf("Visitei: %c\n",key(h->item)); //Preorder
    
    tranverse(h->esq); // se a função de visita printf começar por aqui é inorder.
    tranverse(h->dir); // e aqui é Posordem.
}


link NEW(Item item, link esq,link dir)){
    link x = malloc(sizeof(*x));
    x -> item = item;
    x -> esq = esq;
    x -> dir = dir;
    return x;
}

void link(link h){

    return NEW(NULLITEM, NULL, NULL);
}

void STinsert(Item item, link h){
    h = insertR(h,item);
}

link insertR(link h,Item item){
    key v = key(item), t=key(h->item);

    if(h==NULLNODE)
        return NEW(item,NULL,NULL);
    if(less(v,t))
        h->esq = insertR(h-> esq, item);
    else
        h -> dir = insertR(h -> dir, item);
    return h;
}

// Preorder: visitamos o nó, depois visita o da esquerda e depois o da direita
// Inorder: visita a subarvore da esquerda, visita o nó, visita a subarvore da direita
// Posorder: visito as subarvores esquerda,direita, nó.


Item searchR(link h, key v){
    if(h ==NULL)
        return NULL;
    key t = key(h -> item);
    if(eq(v,t))
        return &h -> item;
    if(less(v,t))
        return searchR(h->esq,v);
    else
        return searchR(h -> dir, v);
}

int main(){
    link h = NULL;
    int x;
    scanf("%d",x);
    STinsert(x,h); 
    return 0;
}