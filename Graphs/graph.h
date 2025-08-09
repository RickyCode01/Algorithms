/* header file of graph */

/* status of vertex in a visit: 
    white = not visited
    gray = active
    black = completely visited
*/
typedef enum {white, gray, black} status;

// vertex of a graph = point of information
typedef struct vertex{
    int value; // value containing information of node
    size_t distance; // distance from a source
    status color; // status of a vertex
    struct vertex *next; // pointer to next vertex on adj list
}vertex;

// edge of a graph = couple of verticies
typedef struct edge{
    int weigth; // weigth of edge
    char type; // type of edge
    vertex source;
    vertex destination;
}edge;

// struct of a graph
typedef struct graph{
    int n; // number of verticies
    int m; // number of edges
    vertex **Adj; // adiacency list
}graph;

//struct for FIFO graph element
typedef struct FIFO{
    vertex *v; // vertex element stored
    struct FIFO *next; // pointer to first vertex of list
}fifo;

// fun to create a vertex of graph
vertex* createVertex(int val, status state, vertex *next);

// create a graph of n verticies labeled from 0 to n-1 without edges
graph* createGraph(int *Verticies, int (*Edges)[][2], int n, int m);

// free all space used by graph
void freeGraph(graph *g);

// print graph in terminal
void printGraph(graph *g);


