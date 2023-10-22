/* header file to use functions in randArr */
#include <stdbool.h>

// function to swap to elements from array
extern void Swap(int *A, int a, int b);
// function to create an array initilized to zero value
extern int * zeroArray(int len);
/* function to get a random intger array -> return pointer to array
min/max = minimum/maximum value of int */
extern int *randIntArr(int len, int min, int max);
// function to print array
extern void printArray(int *A, int start, int end, bool space);
