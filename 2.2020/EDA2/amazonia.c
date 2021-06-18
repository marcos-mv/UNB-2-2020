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


static int cnt, pre[1000];
static int cntt, post[1000];
static Edge e[1000];

void dfsR(Graph G, Edge e){
    int t; 
    int w = e.w;

    pre[w]= cnt++;
    for(t = 0; t<G->V, t++){
        if(G -> adj[w][t]!=0){
            if(pre[t]==-1){
                dfsR(G, EDGE(w,t));
            }
        }
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


int main()
{
    while (scanf("%d\n", &n) == 1)
    {
        if (n == 0) break;

        for (int i = 0; i < n; i++)
    {
        scanf("%d %d\n", &locX[i], &locY[i]);
    }

    calcDist();
    for (int i = 0; i < n; i++) visitado[i] = false;
    dfs(0);
    bool alcancaveis = true;

    for (int i = 0; i < n; i++){
        if (!visitado[i]) {
        alcancaveis = false;
        break;
        }
    }

    if (alcancaveis) printf("All stations are reachable.\n");
    else printf("There are stations that are unreachable.\n");
    }
    return 0;
}