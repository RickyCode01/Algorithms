/* define struct node of bin tree */

typedef struct Node{
    int key;
    struct Node* childsx;
    struct Node* childdx;
    struct Node* father;
}Node;

// fun to allocate dinamic memory(heap) for nodes
extern Node* newNode(int key, Node* childsx, Node* childdx, Node* father);