#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

vertex* createVertex(int val, status state, vertex *next){
    vertex *v = (vertex *)malloc(sizeof(vertex));
    v->value = val;
    v->color = state;
    v->next = next;
    return v;
}

void freeGraph(graph *g){
    for (size_t i = 0; i < g->n; i++){
        vertex *follower;
        while(g->Adj[i]->next != NULL){
            follower = g->Adj[i];
            g->Adj[i] = g->Adj[i]->next;
            // printf("free[%d] ", follower->value);
            free(follower);
        }
        // printf("free[%d]\n", g->Adj[i]->value);
        free(g->Adj[i]);
    }
    free(g);
}

void printGraph(graph *g){
    // create verticies of list
    for (size_t i = 0; i < g->n; i++){
        vertex *trace = g->Adj[i];
        while(trace->next != NULL){
            printf("%d -> ", trace->value);
            trace=trace->next;
        }
        printf("%d\n", trace->value); // print last value of list
    }
}

graph* createGraph(int *Verticies, int (*Edges)[][2], int n, int m){
    graph *g; // pointer to a graph
    // allocate memory
    g = malloc(sizeof(struct graph));
    // define fields
    g->n = n;
    g->m = m;

    // create adiacency list: list of pointers to vertex
    g->Adj = malloc(sizeof(vertex*)*n);

    size_t j = 0;
    // create verticies of list
    for (size_t i = 0; i < n; i++){
        g->Adj[i] = createVertex(Verticies[i], white, NULL);
        // printf("%d - %d\n", (*Edges)[i][1], g->Adj[i]->value);
        vertex *trace = g->Adj[i]; // vertex follower to hold trace of single list and link vertex togheter
        while((*Edges)[j][0] == g->Adj[i]->value){
            //printf("%d ", (*Edges)[j][1]);
            trace->next = createVertex((*Edges)[j][1],white,NULL);
            trace=trace->next;
            j++; // increment line
        }
        // printf("\n");
    }
    printGraph(g);
    freeGraph(g);
    //free(g->Adj);
    
    return g;
}


int main(int argc, char const *argv[]){
    int Verticies[5] = {1,2,3,4,5};
    int Edges[14][2] = {{1,2},{1,5},
    {2,1},{2,5},{2,3},{2,4},
    {3,2},{3,4},
    {4,2},{4,5},{4,3},
    {5,4},{5,1},{5,2}};
    createGraph(&Verticies, &Edges, 5, 7);
    return 0;
}

