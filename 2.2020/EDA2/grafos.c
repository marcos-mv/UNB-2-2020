// grafo é um conjunto de vértices e um conjunto de arestas.

// vertices são numerados de zero ate v-1

// Grafos dirigidos existe um apontamento na direção possivel que pode ser seguida.

// Grafo completo. todo mundo tem que se conectar com todo mundo.
// um grafo com V vertices tem no máximo v(v-1)/2

#define vertex int

typedef struct grafos
{
    int v;
    int w;
}Edge;

Edge EDGE(int,int);

typedef struct graph *Graph;

Graph GRAPHInit(int);  //quantidade de vértices

void GRAPHInsertE(Graph, Edge);

void GRAPHRemoveE(Graph, Edge);

int GRAPHEdges(Edge[],Graph G);

Graph GRAPHCopy(Graph);

void GRAPHDestroy(Graph);

// Matriz de adjascência.

struct graph
{
    int V;
    int E;
    int **adj;
    int **tc;
};

GraphInit(int V){
    Graph G = malloc(sizeof(*G));
    G -> V = V;
    G -> E = 0;
    G -> adj = MATRIXInit(V,V, 0);
    return G;
}

void GRAPHInsertE(Graph G, Edge e){
    int v = e.v;
    int w = e.w;

    if(G -> adj[v][w]==0){
        G -> E++;
    }
    G ->adj[v][w]=1;
    G ->adj[w][v]=1;
}

void GRAPHRemoveE(Graph G, Edge e){
    int v = e.v;
    int w = e.w;

    if(G -> adj[v][w]==1){
        G->E --;
    }
    G -> adj[v][w] = 0;
    G -> adj[v][w] = 0;
}

int GRAPHEdges(Edge a[], Graph G){
    int v, w, E = 0;
    for (v = 0; v < G -> V; v++){
        for(w = v+1; w< G -> V; w++){
            if(G -> adj[v][w] == 1){
                a[E++]=EDGE(v,w);
            }
        }
    }
    return E;
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função MATRIXint() aloca uma matriz com linhas 0..r-1 e colunas 0..c-1. Cada elemento da matriz recebe valor val. */
static int **MATRIXint( int r, int c, int val) { 
   int **m = malloc( r * sizeof (int *));
   for (vertex i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof (int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

//lista Encadeada

typedef struct node *link;

struct node{
    int v;
    link next;
};

struct graph{
    int V, E;
    link *adj;
};

link NEW(int v, link next){
    link x = malloc(sizeof *x);

    if(x == NULL){
        tela_azul();
    }
    x->v = v;
    x -> next = next;
    return x;
}

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

void GRAPHInsert(Graph G, Edge e){
    int v = e.v , w = e.w;
    G->adj[v] = NEW(w, G->adj[v]);
    G->adj[w] = NEW(v, G->adj[w]);
    G-> E++;
}

int GRAPHEdges(Edge a[],Graph G){
    int v, E=0;
    link t;

    for(v = 0; v<G->V; v++){
        for(t = G ->adj[v]; t!= NULL; t= t->next){
            if(v < t -> v ){
                a[E++]=EDGE(v,t->v);
            }
        }
    }
    return E;
}

//Busca em profundidade DFS

int pre[v];

static int cnt, pre[mexV];

void dfsR(Graph G, Edge e){
    int t, w = e.w;

    pre[w]= cnt++;
    for(t = 0; t<G->V, t++){
        if(G -> adj[w][t]!=0){
            if(pre[t]==-1){
                dfsR(G, EDGE(w,t));
            }
        }
    }
}

void dfs(Graph G, Edge e){
    int t, w = e.w;
    link l;
    pre[w]= cnt++;
    for(l =G ->adj[w]; l!= NULL; l=l->next){
        t =l -> v;
        if(pre[t]==-1){
            dfs(G, EDGE(w,t));
        }
    }
}

void GRAPHSearch(Graph G){
    int v; 
    int conexos = 0;
    int cnt =0;
    for(v=0; G -> V; v++){
        pre[v] = -1;
    }
    for(v=0; v< G ->V; v++){
        if(pre[v] == -1){
            dfsR(G, EDGE(v,v));
            conexos++;
        }
    }
}

void bfs(Graph G, Edge e){
    int v, w;
    Queveput(e);
    pre[e.w] = cnt++;
    while(!Queveempty()){
        e = Queveget();
        w = e.w;
        for(l = G -> adj [w]; l!=NULL; l = l ->next){
            t = l -> v;
            if(pre[t]==-1){
                Queveput(EDGE(w,t));
                pre[t] = cnt++;
            }
        }
    }
}
//Grafos Dirigidos (Digraphs)

// Grafo dirigido(ou digrafo) é um conjunto de vértices e um conjunto de arestas dirigidas que conectam um  par 
// de vértices(SEM ARESTAS DUPLICADAS).

// Dizemos que uma aresta vai de DE um primeiro vértice para o seu segundo vértice.

// EDGE{ int v, w}

// v -> w

// Caminho Dirigido em um digrafo é uma lista de vértcies no qual existe uma aresta dirigida conectando
// cada vertice da lista a seu sucessor. Dizemos que um vertice T é ALCANÇAVEL de um vértice S se existe
// um caminho dirigido de S a T.

// Quantidade de arestas em um grafo não dirigido V², já em um grafo dirigido pode ser 2^V².

// Como inverter as arestas de um grafo dirigido?

Graph GRAPHReverse(Graph G){
    int v;
    link t;

    Graph R = GRAPHinit(G->V);

    for(v=0; v< G -> V; v++){
        for(t = G ->adj[v]; t!=NULL; t=t -> next){
            GRAPHInsert(R, EDGE(t->v,v));
        }
    }
    return R;

}

// Grafo dirigido aciclico (DAG - directed acyclic graph)
// é um grafo dirigido que não possui ciclos.

// Grafo dirigido fortemente conexo: se todos os vértices são alcançaveis a partir de todos os vértices


//Floyd Warsall -> fecho transitivo

int GRAPHreach(Graph G, int s, int t);

void GRAPHtc(Graph G){
    int i, s, t;
    G -> tc = MATRIXint(G-> V, G-> V, 0);
    for(s = 0; s< G -> V; s++){
        for(t=0; t<G->V; t++){
            G->tc[s][t]=G->adj[s][t];
        }
    }
    for(s=0; s<G->V; s++){
        G->tc[s][s]=1;
    }
    for(i =0; i<G->V; i++){
        for(s =0; s< G->V; s++){
            if(G->tc[s][i] == 1){
                for(t =0; t<G->V; t++){
                    if(G->tc[i][t] == 1){
                        G->tc[s][t]=1;
                    }
                }
            }
        }
    }
    int GRAPHreach(Graph G, int s, int t){
        return G->tc[s][t];
    }
}

bool GRAPHcptBF(Graph G, int s, int *pa, int, *dist){
    bool onqueue[1000];
    for(int v = 0; v <G-> V; v++){
        pa[v]= -1;
        dist[v]=__INT_MAX__;
        onqueue[v]=false;
    }
    pa[s]= s;


}




int main(){
    INICIAGRAPH();
    for(int N= 0; v < G->V; v++){
        pre[v] = -1;
    }
    dfsR(G, EDGE(0,0));
}





