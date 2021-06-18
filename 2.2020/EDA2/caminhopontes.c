#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct grafos{
    int v;
    int w;
}Edge;

typedef struct node *link; 
struct node{
    int v; 
    link next;
    int c; 
};

typedef struct graph *Graph;
struct graph{
    int V; 
    int E;
    link *adj;
    int **tc;
};

void GRAPHInsertE(Graph, Edge);

link NEW(int v, link next, int c){
    link x = malloc(sizeof *x);

    if(x == NULL){
       printf("null.");
    }
    x->v = v;
    x -> next = next;
    x -> c = c;
    return x;
}

// GraphInit(int V){
//     Graph G = malloc(sizeof(*G));
//     G -> V = V;
//     G -> E = 0;
//     G -> adj = MATRIXInit(V,V, 0);
//     return G;
// }

Graph GRAPHInit(int V){
    int v;
    Graph G = malloc(sizeof(*G));
    G -> V = V;
    G -> E = 0;
    G -> adj = malloc(V * sizeof(link));
    for(v = 0; v<V; v++){
        G ->adj[v]= NULL;
    }
    return G;
}

void GRAPHInsert(Graph G, Edge e, int c){
    int v = e.v; 
    int w = e.w;
    G -> adj[v] = NEW(w, G->adj[v], c);
    G -> adj[w] = NEW(v, G->adj[w], c);
    G-> E++;
}

Edge EDGE(int v, int w){
    Edge e; 
    e.v = v; 
    e.w = w; 
    return e;
}

void GRAPHcbtD1(Graph g, int s,  int *pa, int *dist){ //DIJKSTRA (ingênuo) -> caminhos mínimos, somentes positivos.
    bool mature[10000]; 

    for(int v = 0; v < g->V; v++){
        pa[v] = -1; 
        mature[v] = false;
        dist[v] = INT_MAX;
    }

    pa[s] = s;
    dist[s] = 0;

    while(true){
        int min= INT_MAX; 
        int y;
        
        for(int z = 0; z < g->V; z++){
            if(mature[z]){
                continue;
            }
            if(dist[z] < min){
                min = dist[z], y =z;
            }
        }
        if(min == INT_MAX){
            break;
        }

        for(link a =g->adj[y]; a!=NULL; a= a->next){
            if(mature[a->v]){
                continue;
            }
            if((dist[y]+ a->c)< dist[a->v]){
                dist[a->v] = dist[y] + a->c; 
                pa[a->v] = y; 
            }
        }
    mature[y] = true;
    }
}

int main(){

    int numPilar, numPontes, count=0; 

    scanf("%d %d",&numPilar, &numPontes); 

    Graph g = GRAPHInit(numPilar+2); 
    int *pa = malloc((numPilar+2) * sizeof(int)); 
    int *dist = malloc((numPilar+2) * sizeof(int)); 

    for(int i =0; i < numPontes; i++){
        int pilarS, pilarT, numBuracos; 
        while(scanf("%d %d %d", &pilarS, &pilarT, &numBuracos) == 3){
            GRAPHInsert(g, EDGE(pilarS, pilarT), numBuracos);
        } 
    }
    GRAPHcbtD1(g,0,pa,dist); 

    printf("%d\n", dist[numPilar+1]);

    return 0;
}