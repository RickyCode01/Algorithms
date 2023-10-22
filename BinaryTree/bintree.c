#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bintree.h"

Node* newNode(int key, Node* childsx, Node* childdx, Node* father){
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->childsx = childsx;
    node->childdx = childdx;
    node->father = father;
    return node;
}

void Insertion(Node* root, Node* node){
    Node* x = root; // scan tree pointer
    Node* y = x->father; // follow pointer
    while(x != NULL){ // go down tree until find null pointer
        y = x; 
        if(x->key < node->key){x = x->childdx;}
        else {x = x->childsx;}
    }
    // y contains last node not null in tree
    node->father = y; // attach new node to father
    // following lines attach father to new node to sx or dx child
    if(y == NULL){root = node;} // if root not exist
    else if(node->key < y->key){y->childsx = node;}
    else {y->childdx = node;}
};

void InorderVisit(Node* root){
   if(root->childsx != NULL)InorderVisit(root->childsx);
   printf("[%d]->", root->key);
   if(root->childdx != NULL)InorderVisit(root->childdx);
}

void PostorderFreeMem(Node* scan){
   /* postorder traversal allow to free memory visiting childs before parents recursively
    freeing memory at each node not NULL */
   if(scan->childsx != NULL)PostorderFreeMem(scan->childsx);
   if(scan->childdx != NULL)PostorderFreeMem(scan->childdx);
   if(scan != NULL){
      printf("free:%d\n", scan->key);   
      free(scan);
   }
}

Node* createRandTree(int len, int min, int max){
   srand((unsigned) time(NULL)); // random seed generator
   Node* root = (Node*)newNode(rand() % (max-min+1), NULL, NULL, NULL);
   for (size_t i = 0; i < len; i++){
      Node* node = (Node*)newNode(rand() % (max-min+1), NULL, NULL, NULL);
      Insertion(root, node);
   }
   return root;
}

Node* createIntTree(int Keys[], int size){
   if(size != 0){
      Node *root = (Node*)newNode(Keys[0], NULL, NULL, NULL);
      for (size_t i = 1; i < size; i++){
         Node *node = (Node*)newNode(Keys[i], NULL, NULL, NULL);
         Insertion(root, node);
      }
      return root;
   }else{
      return NULL;
   }
   
   
}

int Maximum(Node* root){
   if(root != NULL){
      Node* scan = root;
      // go ahead to right until next child is last
      while(scan->childdx != NULL)scan=scan->childdx;
      return scan->key; // return last child to the right
   }else{
      return -1;
   }
}

int Minimum(Node* root){
   if(root != NULL){
      Node* scan = root;
      // go ahead to left until next child is last
      while(scan->childsx != NULL)scan=scan->childsx;
      return scan->key; // return last child to the left
   }else{
      return -1;
   }
}

Node* Search(Node* root, int key){
   Node* scan = root;
   while(scan != NULL){ // search in tree until reach leafs
      if(key < scan->key){scan=scan->childsx;}
      else if(key > scan->key){scan=scan->childdx;}
      else{return scan;}
   }
   return scan;
}

int main(int argc, char const *argv[])
{   
   int arr[10] = {0,34, 53, 1, 35, 46, 78, 9, 11, -2};
   Node* root = createIntTree(arr, sizeof(arr)/sizeof(arr[0]));
   int min = Minimum(root);
   int max = Maximum(root);
   printf("Tree root:%d, min:%d, max:%d\n",root->key, min, max);
   InorderVisit(root);
   puts("\n");
   Node* scan = root;
   PostorderFreeMem(scan);
   // printf("root node at addr:%p -> key:%d\n",root, root->key);
   return 0;
}
