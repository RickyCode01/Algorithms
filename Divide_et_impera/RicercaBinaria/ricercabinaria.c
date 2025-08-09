#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../Sorting-Number/ArrayLib/randArr.c"
#include "../../../Sorting-Number/Insertionsort/insertionsort.c"


int BinarySearch(int *A, int start, int end, int key){
    // printArray(A, start, end, false);
    if (end > start){
        int half = (start + end)/2;
        printf("start:%d, end:%d -> half:%d\n", start, end, half);
        if (A[half] < key) return BinarySearch(A, half+1, end, key);
        if (A[half] > key) return BinarySearch(A, start, half-1, key);
        return half;
    }
    return (A[start] == key) ? start : -1;
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
        size_t index = -1;
        for(size_t i=end; i >= start; i--){
            if (A[i] == key) index = i;
        }
        return index;
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
        size_t index = -1;
        for (size_t i=start; i <= end; i++){
            if (A[i] == key) index = i;
        }
        return index;
    } 
}

int Occurences(int *A, int start, int end, int key){
    size_t first = searchFirst(A, start, end, key);
    if (first == -1) return -1;
    size_t last = searchLast(A, start, end, key);
    if (last == first) return 1;
    return last - first + 1; // index start to 0
}

const int LENGTH = 50; // costante lunghezza array

int main(int argc, char const *argv[])
{
    /* test ricerca binaria */
    // int A[LENGTH] = {-2 ,0, 2, 4, 8 ,16, 55};
    // printArray(&A, 0, LENGTH, false);
    // int key = 55;
    // printf("key:%d -> index:%d\n", key, BinarySearch(&A, 0, LENGTH-1, key));

    /* test ricerca primo ed ultimo elemento */
    // int A[LENGTH] = {1,2,4,5,5,5,7,9,10,10}; // ordered array
    // printArray(&A, 0, LENGTH, false);
    // int key = 5;
    // printf("first:%d - end:%d\n", searchFirst(&A, 0, LENGTH-1, key), searchLast(&A, 0, LENGTH-1, key));
    // printf("occurences of %d: %d\n", key, Occurences(&A, 0, LENGTH-1, key));

    /* test time */
    
    // struct timespec start, end;
    unsigned long long start , end;
    int *A = randIntArr(LENGTH, 0,10);
    InsertionSort(A, 0, LENGTH);
    printArray(A, 0, LENGTH, false);
    int key = 11;
    start = clock_gettime_nsec_np(CLOCK_REALTIME);
    printf("occurences of %d: %d\n", key, Occurences(A, 0, LENGTH-1, key));
    end = clock_gettime_nsec_np(CLOCK_REALTIME);
    printf("time:%llu us\n", (end-start)/1000);

    return 0;
}
