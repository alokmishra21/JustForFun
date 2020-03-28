
void swap (int &a, int&b )
{
    int t = a;
    a = b;
    b = t;
}

void merge(int *arr, int& N, int l, int m, int r)
{
    int aL[m - l + 1];
    int aR[r - m];
    
    for (int i = l; i <= m; i++)
        aL[i - l] = arr[i];
    for (int i = m + 1; i <= r; i++)
        aR[i - m - 1] = arr[i];
    int i = 0,
        j = 0,
        k = l;
    while( i < m - l + 1 && j < r - m)
    {
        if ( aL[i] < aR[j] )
        {
            arr[k++] = aL[i++];
        }
        else arr[k++] = aR[j++];
    }
    // copy the remaining left sub-array
    while(i < m - l + 1)
    {
        arr[k++] = aL[i++];
    }
    // copy the remaining right sub-array
    while(j < r - m)
    {
        arr[k++] = aR[j++];
    }
}
void merge_sort(int *arr, int& N, int l, int r)
{
    if (r > l)
    {
        int m = (l + r) / 2;
        merge_sort(arr, N, l, m);
        merge_sort(arr, N, m + 1, r);
        
        merge(arr, N, l, m, r);
    }
    /*
        TC = theta(NlogN)
        SC = O(N)
        in-line: no 
        stable: yes
    */
}
void insertion_sort (int *arr, int& N)
{
    for (int i = 1; i < N; i++)
    {
        int j = i - 1; 
        int key = arr[i];
        
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    /*
        TC = O(N^2)
        SC = O(1)
        in-place sorting, stable.
    */
}
void bubble_sort (int *arr, int& N)
{
    bool swapped = true;
    for (int i = 0; i < N; i++)
    {
        if (!swapped) 
            break;
        swapped = false;
        for (int j = i+1; j < N; j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]), swapped = true;
        }
    }
    /*
        TC = O(N^2)
        SC = O(1),
        it does N*N swaps in worst case.
        in-place and stable sorting.
    */
}
void selection_sort (int *arr, int& N)
{
    for (int i = 0; i < N; i++)
    {
        int index = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
        }
        if (index != i)
            swap(arr[i], arr[index]);
    }
    /*
        TC = O(N^2)
        SC = O(1),
        it does N swaps in worst case. Not stable.
    */
}
int main() 
{
    int arr[] = { 3, 2, 5, 20, 1, 4, -1 };
    int N = sizeof(arr) / sizeof(int);
    
    // selection_sort(arr, N);
    // bubble_sort(arr, N);
    // insertion_sort(arr, N);
    merge_sort(arr, N, 0, N-1);
    for (int i = 0; i < N; i++)
        cout << arr[i] << "\t";
}
