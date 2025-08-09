#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

/* Queue FIFO(First In First Out) = A queue in which the elements entered first are
the first to leave */

// function to queue new vertex
fifo* ENQUEUE(fifo* queue, vertex* vertex){
    fifo *node = malloc(sizeof(fifo)); // create new fifo node
    node->v = vertex;
    if(queue == NULL)return node;
    fifo* scan = queue; // save first fifo node
    while(scan->next != NULL)scan = scan->next; // scan for last node
    scan->next=node; // attach next pointer to new fifo node (LAST ELEMENT:FIFO)
    return queue;
}

// funtion to dequeue head node
vertex* DEQUEUE(fifo** queue){ // pass pointer to pointer to fifo in order to work with original pointer dereferencing it 
    if (*queue != NULL){
        vertex* v = (*queue)->v; // save pointer to vertex to return
        fifo* temp = *queue; // save pointer to FIFO node to free
        if((*queue)->next != NULL) (*queue)=(*queue)->next; // set head to next node if next node exist
        free(temp); // free node
        return v; // return vertex;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{   
    vertex *v[3];
    fifo *queue = NULL;
    for (size_t i = 0; i < 3; i++){
        v[i] = createVertex(i, white, NULL);
        queue = ENQUEUE(queue, v[i]);
    }
    // printf("%d\n", queue->v->value);
    for (size_t i = 0; i < 3; i++){
        printf("%d ", DEQUEUE(&queue)->value);
        free(v[i]);
    }
    return 0;
}
