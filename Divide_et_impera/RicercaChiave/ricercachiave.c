#include <stdlib.h>
#include <stdio.h>

size_t searchKey(int A[10], size_t start, size_t end, int key, size_t index){
    if(start < end){
        size_t half = (start+end)/2;
        index = searchKey(A, start, half, key, index);
        if(index < 0){
            index = searchKey(A, half+1, end, key, index);
        }else{
            return index;
        }
    }else{ // start = end
        if (A[start] == key){
            return start;
        }
    }
}


int main(int argc, char const *argv[])
{   
    int A[10] = {2,1,0,4,67,32,11,29,11,13};
    int ikey = searchKey(A, 0, 9, 0, -1);
    printf("index key: %d\n", ikey);    
    return 0;
}


