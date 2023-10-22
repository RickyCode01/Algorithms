#include <stdlib.h>
#include <stdio.h>

const int LENGHT = 10;

void PrintArr(int* A, int start, int end){
    printf("[");
    for (size_t i = start; i < end; i++)
    {   
        if(i < end-1){ // -1 cause array start from 0
            printf("%d, ", A[i]);
        }else{
            printf("%d", A[i]);
        }
    }
    printf("]\n");
}

int counterOccurences(int *A, int key, int start, int end){
    if(end-start+1 > 3){
        int half = (start+end)/2;
        // PrintArr(A, start, end);
        // printf("half:%d\n", half); // debug code
        if (A[half] < key){ // key on left side
            return counterOccurences(A, key, half+1, end);
        }else if (A[half] > key){ // key on right side
            return counterOccurences(A, key, start, half-1);
        }else{ // found key
            int isx = half;
            int idx = half;
            while(isx > start && A[isx-1] == key)isx--;
            while(idx < end && A[idx+1] == key)idx++;
            printf("value %d found at %d index\n", key, half);
            // printf("start: %d\n", isx);
            // printf("end: %d\n", idx);
            return idx-isx+1; // add +1 cause array start from 1
        }
    }else{ // check remaining values
        // printf("s:%d, e:%d\n", start, end);
        // PrintArr(A, start, end+1);
        int count = 0;
        for (size_t i = start; i <= end; i++){
            if(A[i]==key){
                printf("value %d found at %d index\n", key, i);
                count++;
            }
        }
        return count;
    }
    
}


int main(int argc, char const *argv[])
{
    int A[10] = {1,2,4,5,5,5,7,10,10,10}; // ordered array
    int key =10;
    PrintArr(A, 0, LENGHT);
    printf("number of occurences of %d: %d\n", key, counterOccurences(&A, key, 0, LENGHT));

    return 0;
}
