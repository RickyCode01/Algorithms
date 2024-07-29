#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "MinPriorityQueue.h"

void Swap(int *A, int a, int b){
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void Min_Heapfy(int *A, int i, int n){
    int k = i;
    if(2*i+1 < n && A[2*i+1] < A[i]) k = 2*i+1;
    if(2*i < n && A[2*i] < A[k]) k = 2*i;
    if(k != i){
        Swap(A, i, k);
        Min_Heapfy(A, k, n);
    }
}

mPQ* Build_mPQ(int *A, int start, int end){
    mPQ* mQueue = (mPQ*)malloc(sizeof(mPQ));
    mQueue->end = end;
    mQueue->lenght = end-start;
    for (int i = end/2-1; i >= 0; i--){ // use int not size_t because index can be < 0
        Min_Heapfy(A, i, end);
    }
    mQueue->queue = A;
    return mQueue;
}

int Extract_min(mPQ* mQueue){
    if(mQueue->lenght > 1){
        mQueue->start++;
        mQueue->lenght--;
        return mQueue->queue[0];
    }
    return INT32_MAX;
}

void PrintQueue(mPQ* mQueue){
    int lenght = mQueue->lenght;
    int start = mQueue->start;
    int end = mQueue->end;
    int *A = mQueue->queue;
    printf("{");
    for (size_t i = start; i < end-2; i++){
        printf("%d -> ", A[i]);
    }
    printf("%d}\n", A[end-2]);
}

int main(int argc, char const *argv[])
{
    int A[8] = {54, 11, 34, 22, 11, 13, 7, 96};
    // Min_Heapfy(A, 0, 9);
    mPQ* minQueue = Build_mPQ(A, 0, 9);
    // printf("start:%d, end:%d\n", minQueue->start, minQueue->end);
    PrintQueue(minQueue);
    printf("min extracted: %d\n", Extract_min(minQueue));
    PrintQueue(minQueue);
    return 0;
}
