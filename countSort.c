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

/*
    Counting sort
        an efficient algorithm for solving values with limited range
        invented by Harold H. Seward in mid 1950s
        Running time - O(n + k), n = size, k = size
        can only sort integers
        small integers with multiple counts

    Harold H. Seward
        invented theoritic sort and count sort in 1945
        a computer scientist, inventor, engineer

    Idea
        1. Find the max element in an array
        2. Initialize array length with max + 1
        3. Store the count of elements in the index in array
        4. Calculate commulative frequency of count array
        5. Fix the values of the sorted array

    Application
         small ints with multiple counts
*/