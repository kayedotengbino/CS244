void quickSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int pi = partition(arr, l, r);

        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

void swap(int *a, int *b)
{
    (*a) ^= (*b) ^= (*a) ^= (*b);
}

void partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for(int j = l; j < r; j++)
    {
        if(array[j] <= pivot)
        {
            i++;
            swap(&pivot[i], &pivot[j]);
        }
    }

     swap(&pivot[i + 1], &pivot[r]);

     return i + 1;
}

/*
    Quick Sort
        partition exchange sort
        developed by Tony Hoare in 1959
        uses divide and conquer technique
        Running is T(n/2) + T(n/2) + O(n) - partition
            Best and Average case: O(nlogn)
            Worst case: O(n^2) - pivot is the least/greatest

    Application
        Quicksort is used everywhere where a stable sort is not needed
        Variants of quicksort are used to separate the k smallest or largest elements
        Quicksort's divide-and-conquer enables the use of parallelization
        Quick Sort is a cache friendly sorting algorithm as it has good locality of reference when used for arrays
        Quick Sort is tail recursive and hence, all tail call optimizations can be done
        Quick Sort is an in-place sort that is does not require any extra storage
*/