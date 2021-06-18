#include <stdio.h>
#include <stdlib.h>
#define hash(v,m) (v % m) // ok para m primo
#define hash(v,m) (618033 * (unsigned) v) %m)


typedef struct Item
{
    int chave;
    long e1, e2;
    long elemento;
}Item; Item NULLITEM = {0,0,0,0};

#define Key(x) (x.chave)
#define less(a,b) (key(a)<key(b))
#define null(A) (key (h+[A])== key (NULLITEM))

static int N, M;
static Item *ht;

void HTInit(int max){
    int i;
    n=0; m=2*max;
    ht=malloc(sizeof(Item)*M);
    for(i=0;i<m;i++){
        ht[i]=NULLITEM;
    }
}

int HTcount(){return N;}
void HTinsert(Item item){
    int v = key(item);
    int i = hash(v,m);

    ht[i] = item;

    while(!null(i)) i = i +1 % m;
    ht[i]= item;
    n++;
}

Item HTsearch(int v){
    int i = hash(v,m);
    while(!null(i))
        if(eq(v,key(ht[i])))
            return st[i];
        else
        i = i + 1 % M;
    return NULLITEM;
}

