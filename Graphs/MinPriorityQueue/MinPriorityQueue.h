
typedef struct MinPriorityQueue{
    int lenght;
    int start;
    int end;
    bool ordered;
    int *queue;
}mPQ;


mPQ* Build_mPQ(int *A, int start, int end); // Build Minimum Priority Queue from array A
int Extract_min(mPQ* mQueue); // Extract minimum element from Heap
void PrintQueue(mPQ* mQueue); // Print queue out