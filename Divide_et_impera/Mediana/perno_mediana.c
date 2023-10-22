#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "randArr.h"

const int SIZE = 15;

int InsertionSort(int *A, int p, int r){
  int i,j,key;
  for(i=p+1; i<=r; i++){
      key = A[i];
      j = i-1;
      while(j >= p && A[j] > key){ // se gli elementi prima della chiave sono maggiori
          A[j+1] = A[j]; // li sposto avanti
          j--; // j = j - 1
      }
      A[j+1] = key; // inserisco la chiave
  }
  printArray(A, p, r+1, false);
  return A[((r+p)/2)];
}

int medianaMediane(int *A, int p, int r){
  // printf("[n/2]+1:%d\n", ((r+p)/5)+1);
  int gruppi = ((r+p)/5)+1;
  int mediane[gruppi]; // array mediane gruppi
  int copia[gruppi]; // array copia per posizione gruppi originale
  int i;
  for (i = 0; i < gruppi; i++){
      mediane[i] = InsertionSort(A, i*5, (i*5)+4);
      copia[i] = mediane[i];
  }
  printArray(mediane, p, gruppi, false);
  i = 0; // resetto l'indice per riutilizzarlo per ritrovare la posizione del perno nell'array
  int perno = InsertionSort(mediane, 0, gruppi-1);
  while(copia[i] != perno)i++; // i = al gruppo dove si trova la mediana
  // printf("perno:%d, i:%d\n", perno, i);
  perno = (i > 0) ? ((i+1)*5)-3 : 2; // ricavo la posizione tramite il gruppo
  return perno; // ritorno la posizione della mediana nell'array
}

int main(){
  int *A = randIntArr(SIZE, 0, 100);
  printArray(A, 0, SIZE, false);
  int mediana = medianaMediane(A, 0, SIZE-1);
  printf("mediana:%d -> %d\n", mediana, A[mediana]);
}
