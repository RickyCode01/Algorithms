#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

vertex* createVertex(int val, status state, vertex *next){
    vertex *v = (vertex *)malloc(sizeof(vertex));
    v->value = val;
    v->color=state;
    v->w=next; 
    return v;
}

void freeGraph(graph *g){
    size_t i = 0;
    while(g->Adj[i] != NULL){
        free(g->Adj[i]);
        i++;
    }
    free(g);
}

graph* createGraph(int *Verticies, int *Edges[2], int n, int m){
    graph *g; // pointer to a graph
    // allocate memory
    g = malloc(sizeof(struct graph));
    // define fields
    g->n = n;
    g->m = m;

    // create adiacency list: list of pointers to vertex
    g->Adj = malloc(sizeof(vertex*)*n);

    // create verticies of list
    for (size_t i = 0; i < n; i++){
        g->Adj[i] = createVertex(Verticies[i], white, NULL);
    }

    // verify verticies
    for (size_t i = 0; i < n; i++){
        if (i < n-1){
            printf("%d -> ", g->Adj[i]->value);
        } else {
            printf("%d\n", g->Adj[i]->value);
        }
    }
    
    freeGraph(g);
    //free(g->Adj);
    
    return g;
}



int main(int argc, char const *argv[]){
    int Verticies[6] = {1,3,6,9,10,11};
    // int Edges[7][2] = {{1,2},{}};
    createGraph(&Verticies, NULL, 6, 0);
    return 0;
}

