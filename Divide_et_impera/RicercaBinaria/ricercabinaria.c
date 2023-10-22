#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Sorting-Number/randArr.c"


int BinarySearch(int *A, int start, int end, int key){
    // printArray(A, start, end, false);
    if (start <= end){
        int half = (start + end)/2;
        printf("start:%d, end:%d\n", start, end);
        if (A[half] == key){
            return half;
        }else if (A[half] < key){
            return BinarySearch(A, half+1, end, key);
        }else{
            return BinarySearch(A, start, half-1, key);
        }
    }
    int index = (A[start] == key) ? start : -1;
    return index;
}


int main(int argc, char const *argv[])
{
    int A[6] = {-2 ,0, 2, 4, 8 ,16};
    // printArray(&A, 0, 6, false);
    int key = 2;
    printf("key:%d -> index:%d\n", key, BinarySearch(&A, 0, 6, key));
    return 0;
}
