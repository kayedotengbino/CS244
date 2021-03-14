//main function
void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);   //left
        mergeSort(arr, m+1; r); //right;

        merge(arr, l, m, r);
    }
}

//helper function
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; //left size
    int n2 = r - m; //right size

    //temporary arrays
    int L[n1];  //left
    int R[n2];  //right

    //Copy datas/elements
    for(i = 0; i < n1; i++) 
        L[i] = arr[i + l];  //left
    
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];  //right

    int i = 0, j = 0, k = 1;

    //Store them to their corresponding location
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[i])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //Copy remaining elements if there are any
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/*
Merge sort 
    is an efficient algorithm that is based on divide and conquer
    invented by John Von Neumann in 1945
    discovered by playing cards
    one of the sorting algorithms used for computers
    comparison based
    It has 2 functions
        helper function - void merge(int arr[], int l, int m, int r)    O(n)
        main function - void mergeSort(int arr[], int l, int r) - 2T(n/2)
                            It recursively calls itself twice 
                                for 1st and 2nd half
                            
    this have a stable running time and it is O(nlogn)

John Von Neumann
    hungarian-american, mathematician, physicist, pol-math, computer scientist, engineer

divide and conquer 
    recursively breaks down problems into smaller subproblems

Application
    approaching divide and conquer algorithms
    counting inversion in an array
        how far/close the array is from being sorted
        if sorted, count inversion == 0
    Sorting external/secondary memory
    sorting linked list
    sorting arrays with large number of datas and needs to be stable
*/