#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "binsearchtree.h"

Node* newNode(int key, Node* left, Node* right, Node* father){
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = left;
    node->right = right;
    node->father = father;
    return node;
}

void InsertNode(Node* root, Node* node){
    Node* x = root; // scan tree pointer
    Node* y = x->father; // follow pointer
    while(x != NULL){ // go down tree until find null pointer
        y = x; 
        if(x->key < node->key){x = x->right;}
        else {x = x->left;}
    }
    // y contains last node not null in tree
    node->father = y; // attach new node to father
    // following lines attach father to new node to sx or dx child
    if(y == NULL){root = node;} // if root not exist
    else if(node->key < y->key){y->left = node;}
    else {y->right = node;}
};

void InorderVisit(Node* root){
   if(root != NULL){
      InorderVisit(root->left);
      printf("[%d]->", root->key);
      InorderVisit(root->right);
   }
}

void PostorderFreeMem(Node* scan){
   /* postorder traversal allow to free memory visiting childs before parents recursively
    freeing memory at each node not NULL */
   if(scan != NULL){
      PostorderFreeMem(scan->left);
      PostorderFreeMem(scan->right);
      // printf("free:%d\n", scan->key); 
      free(scan);
   }
}

void PreorderVisit(Node* node){
   if(node != NULL){
      if(node->father == NULL){printf("root:%d\n", node->key);}
      else{
         if(node == node->father->left){printf("child sx of %d: %d\n",node->father->key, node->key);}
         else{printf("child dx of %d: %d\n", node->father->key, node->key);}
      }
      PreorderVisit(node->left);
      PreorderVisit(node->right);
   }
}

Node* createRandTree(int len, int min, int max){
   srand((unsigned) time(NULL)); // random seed generator
   Node* root = (Node*)newNode(rand() % (max-min+1), NULL, NULL, NULL);
   for (size_t i = 0; i < len; i++){
      Node* node = (Node*)newNode(rand() % (max-min+1), NULL, NULL, NULL);
      InsertNode(root, node);
   }
   return root;
}

Node* createIntTree(int Keys[], int size){
   if(size != 0){
      Node *root = (Node*)newNode(Keys[0], NULL, NULL, NULL);
      for (size_t i = 1; i < size; i++){
         Node *node = (Node*)newNode(Keys[i], NULL, NULL, NULL);
         InsertNode(root, node);
      }
      return root;
   }else{
      return NULL;
   }
   
   
}

Node* Maximum(Node* root){
   Node* scan = root;
   // go ahead to right until next child is last
   while(scan->right != NULL)scan=scan->right;
   return scan; // return last child to the right
}

Node* Minimum(Node* root){
   Node* scan = root;
   // go ahead to left until next child is last
   while(scan->left != NULL)scan=scan->left;
   return scan; // return last child to the left
}

Node* Search(Node* root, int key){
   Node* scan = root;
   while(scan != NULL){ // search in tree until reach leafs
      if(key < scan->key){scan=scan->left;}
      else if(key > scan->key){scan=scan->right;}
      else{return scan;}
   }
   return scan;
}

Node* Successor(Node* node){
   // if child right exist, successor is min of right subtree of node
   if(node->right != NULL) return Minimum(node->right);
   Node* parent = node->father;
   /* else successor = first left child in path going up to root,
   if root is reached, node is maximum and successor not exist */
   while(parent != NULL && node == parent->right){
      node = parent;
      parent = node->father;
   }
   return parent;
}

void deleteNode(Node* root, Node* node){
   // tree case: delete node with one child, delete node with two child, delete leaf
   printf("deleting %d node\n", node->key);
   Node* y;
   Node* x; 
   if(node->left == NULL || node->right == NULL){y = node;} // zero or one child
   else{ // two child = copy key of successor of node to node to delete
      y=Successor(node); // successor has one child max 
      node->key = y->key; // logic delete 
   }
   // save child in x
   if(y->left != NULL){x=y->left;}
   else{x=y->right;}
   // change father to child node
   if(x != NULL)x->father=y->father;
   // attach child to father of deleted node
   if(y->father == NULL){root=x;}
   else if(y == y->father->left){
      y->father->left = x;
   }else{
      y->father->right = x;
   }
   free(y); // free memory
}

int main(int argc, char const *argv[])
{   
   int arr[10] = {0,34, 53, 1, 35, 46, 78, 9, 11, -2};
   Node* root = createIntTree(arr, sizeof(arr)/sizeof(arr[0]));
   Node* min = Minimum(root);
   Node* max = Maximum(root);
   printf("Tree root:%d, min:%d, max:%d\n",root->key, min->key, max->key);
   // InorderVisit(root);
   // puts("\n");
   PreorderVisit(root);
   deleteNode(root, root->right);
   // InorderVisit(root);
   // puts("\n");
   PreorderVisit(root);
   // Node* two = Successor(min->father->right);
   // if(two != NULL)printf("Successor of min:%d\n", two->key);
   PostorderFreeMem(root);
   // printf("root node at addr:%p -> key:%d\n",root, root->key);
   return 0;
}
