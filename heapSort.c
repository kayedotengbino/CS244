struct Heap
{
    int size;
    int *array;
    int (*cmp)(int, int);
} *MaxHeap;

//O(nlogn) - worst, O(n)
MaxHeap createAndBuildHeap(int *array, int size, int (*cmp)(int, int))
{
    MaxHeap maxHeap = (MaxHeap)malloc(sizeof(struct Heap));
    maxHeap->array = array;
    maxHeap->size = size;
    maxHeap->cmp = cmp;

    return maxHeap;
}

void swap(int *a, int *b)
{
    (*a) ^= (*b) ^= (*a) ^= (*b);
}

int asc(int a, int b)
{
    return (a > b) - (b < a);
}

int dsc(int a, int b)
{
    return (a < b) - (b > a);
}

//O(logn)
MaxHeap heapify(MaxHeap maxHeap, int idx)
{
    int largest = idx;
    int left = (idx << 1) + 1;
    int right = (idx + 1) << 1;

    if(left < maxHeap->size && maxHeap->cmp(maxHeap->array[left], maxHeap->array[right]) > 0)
        largest = left;

    if(left < maxHeap->size && maxHeap->cmp(maxHeap->array[right], maxHeap->array[left]) > 0)
        largest = right;

    if(largest != idx)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        heapify(maxHeap, largest);
    }
}

void heapSort(int *array, int size, int (*cmp)(int, int))
{
    MaxHeap maxHeap = createAndBuildHeap(array, size, cmp);

    while(maxHeap->size > 1)
    {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;
        heapify(maxHeap, 0);
    }
}

/*
    Heap Sort
        comparison based sorting techinique that is based on BINARY HEAP data structure
        Time complexity is stable - O(nlogn)
        if parents is stored in an array
            left = 2*i+1
            right = 2*i+2
        Space-relevant if implemented in array

    Binary Heap
        complete binary tree where elements are sorted in a special order and satisfies the 
        heap invariant

    Complete Binary Tree
        binary tree where every node, except posibly the last is filled and all nodes are as
        far as left as possible

    Heap Invariant
        parent node is greater/smaller than its 2 child nodes

    Algorithm
        1. Build the maxHeap from input data
        2. Largest element is stored at the root. Replace it with the last item of heap 
           followed by reducing the size by 1. Heapify the root of the tree
        3. Repeat 2 until size is > 1

    Heapify
        can only be heapified if all its child node is heapified
        perform in a bottom-up order

    Location of the node = (size of arr-2)/2
*/