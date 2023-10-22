/* La mediana è il valore in un insieme di n numeri tale che se ordinassimo l'insieme
su una retta esso sarebbe il valore che minimizza la somma delle differenze tra
tutti gli elementi e un punto di riferimento(gathering point). 
Sarebbe a dire che esso è il punto centrale di un insieme ordinato di n elementi */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "randArr.h"

const int SIZE = 20;

void printArrayIndexes(int *A, int start, int end, int i, int j){ // function to print array
    char str[10*(end-start)];
    memset(str, 0, strlen(str));
    str[0]='[';
    char num[15];
    for(int k=start; k<end; k++){
        if(k == i || k == j){
            if(j != i){
                if(k == i){
                    sprintf(num, "(i:%d) ,", *(A+k));
                    strcat(str, num);
                }else{
                    sprintf(num, "(j:%d) ,", *(A+k));
                    strcat(str, num);
                }
            }else{
                sprintf(num, "(j,i:%d) ,", *(A+k));
                strcat(str, num);
            }
        }else{
            sprintf(num, "%d ,", *(A+k));
            strcat(str, num);
        }
    }
    str[strlen(str)-2] = ']';
    str[strlen(str)-1] = '\0';
    printf("%s\n",str);
}

int Partition(int *A, int start, int end, int pivot){
  int i = start;
  int j = end;
  Swap(A, start, pivot); // metto il pivot nella prima posizione
  pivot = A[start]; // metto il valore del pivot al posto del suo indice
  while(i < j){
    while (A[j] >= pivot)j--;
    printArrayIndexes(A, start, end+1, i, j);
    if(i < j){
      Swap(A, i, i+1); // sposto il pivot in avanti
      Swap(A, i, j); // metto l'elemento minore prima del pivot
      i++;
    }
  }
  return i; // ritorno l'ultima posizione del pivot
}

int Mediana(int *A, int p, int r, int m){
    printArray(A, p, r+1, true);
    printf("mediana:%d -> %d\n", m, A[m]);
    // partition viene utilizzato per trovare il rango di m
    int q = Partition(A, p, m, r);
    // se il rango di m è la mediana = n/2 allora l'algoritmo termina
    printf("perno:%d\n", q);
    if(q == m) return A[q];
    if(q > m) return Mediana(A, p, q-1, m);
    if(q < m) return Mediana(A, q+1, r, m);
}

int main(){
    int *A = randIntArr(SIZE, 0, 100);
    // int A[10] =  {2,3,11,6,4,1,5,8,9,7};
    int m = Mediana(A, 0, SIZE-1, (SIZE-1)/2);
    printf("valore mediana:%d\n", m);

//   printArray(A, 0, 10, true);
//   printf("perno:%d -> %d\n", 9/2, A[9/2]);
//   int perno = Partition(A, 0, 9/2, 9);
//   printArray(A, 0, 10, true);
//   printf("perno:%d -> %d\n",perno, A[perno]);
}
