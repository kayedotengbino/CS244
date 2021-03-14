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