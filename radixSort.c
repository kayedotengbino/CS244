//helper function
int getMax(int arr[], int n)
{
    int max = arr[0];

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

void countSort(int arr[], int n, int place)
{
    int i, freq[range] = {0};
    int output[n];

    for(i = 0; i < n; i++)
        freq[(arr[i]/place) % range]++;
    
    for(i = 1; i < range; i++)
        freq[i] += freq[i - 1];

    for(i = n-1; i > 0; i--)
    {
        output[freq[(arr[i]/place) % range]-1] = arr[i];
        freq[(arr[i]/place) % range]--;
    }

    for(i = 0; i < n; i++)
        arr[i] = output[i];
}

//Main function
void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);

    for(int exp = 1; m/exp > 0; exp*=10)
        countSort(arr, n, exp);
}

/*
    Radix Sort
        invented by Herman Hollethir in 1887 for tabulating machines
        non comparison based on the least to the most significant digits
        stable because it preserves the relative order of elemenets that have the same key values
        uses countingSort as a subroutine to sort the application of numbers
        algorithm design technique used 
            sorting algo/exact algorithm
        capable of finding solution to any problem
        O(d(n+b)) 
            d = number of digits of the maximum elements
            n = size
            b = base of the elements
        Application
            Radix Sort for vector multiprocessor
            Comparison of sorting algorithms for the connection machine
            High-performance algorithms on networks of workstation
            Searching for the sorting record
            Fixed length word/fixed alphabet
        
    countingSort makes up the radixSort
*/