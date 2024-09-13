#include <stdio.h>
#include <stdlib.h>
#include "../../../Sorting-Number/ArrayLib/randArr.h"


int BinarySearch(int *A, int start, int end, int key){
    // printArray(A, start, end, false);
    if (end - start > 3){
        int half = (start + end)/2;
        // printf("start:%d, end:%d -> half:%d\n", start, end, half);
        if (A[half] < key) return BinarySearch(A, half+1, end, key);
        if (A[half] > key) return BinarySearch(A, start, half-1, key);
        return half;
    } else { // last 3 values -> O(1)
        for (size_t i=start; i <= end; i++){
            // printf("index:%d\n", i);
            if(A[i] == key) return i;
        }
        return -1; // key not found
    }
}

int searchFirst(int *A, int start, int end, int key){
    if (end - start > 3) {
        int half = (start + end)/2;
        // printf("start:%d, end:%d -> half:%d\n", start, end, half);
        if (A[half] < key) return searchFirst(A, half+1, end, key);
        if (A[half] > key) return searchFirst(A, start, half-1, key);
        return searchFirst(A, start, half, key);
    } else {
        // printf("start:%d, end:%d\n", start, end);
        size_t index=end;
        for(size_t i=end; i >= start; i--){
            if (A[i] == key) index = i;
        }
        return (A[index] == key) ? index : -1;
    } 
}

int searchLast(int *A, int start, int end, int key){
    if (end - start > 3) {
        int half = (start + end - 1)/2;
        // printf("start:%d, end:%d -> half:%d\n", start, end, half);
        if (A[half] < key) return searchLast(A, half+1, end, key);
        if (A[half] > key) return searchLast(A, start, half-1, key);
        return searchLast(A, half, end, key);
    } else {
        size_t index = start;
        for (size_t i=start; i <= end; i++){
            if (A[i] == key) index = i;
        }
        return (A[index] == key) ? index : -1;
    } 
}

int Occurences(int *A, int start, int end, int key){
    size_t first = searchFirst(A, start, end, key);
    if (first == -1) return -1;
    size_t last = searchLast(A, start, end, key);
    if (last == first) return 1;
    return last - first + 1; // index start to 0
}


int main(int argc, char const *argv[])
{
    // int A[6] = {-2 ,0, 2, 4, 8 ,16};
    // printArray(&A, 0, 6, false);
    // int key = 2;
    // printf("key:%d -> index:%d\n", key, BinarySearch(&A, 0, 6, key));
    int A[10] = {1,2,4,5,5,5,7,9,10,10}; // ordered array
    int key = 5;
    // printf("first:%d - end:%d\n", searchFirst(&A, 0, 10, key), searchLast(&A, 0, 10, key));
    printf("number of occurences of %d: %d\n", key, Occurences(&A, 0, 9, key));
    return 0;
}
