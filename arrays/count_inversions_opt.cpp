#include <iostream>
using namespace std;

int merge(int arr[], int l, int mid, int r)
{
    int n1 = mid + 1 - l, n2 = r - mid, inv_count = 0;
    int a[n1], b[n2]; // temp arrays
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {   
            arr[k] = b[j];
            k++;
            j++;
            // Since a[i] > b[j] and i<j. Also all the elements next to a[i] will also be > b[j].
            inv_count += n1-i; 
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return inv_count;
}

int mergeSort(int arr[], int l, int r)
{   
    int inv_count = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        // total number of inversions in left array
        inv_count += mergeSort(arr, l, mid);
        // total number of inversions in right array
        inv_count += mergeSort(arr, mid + 1, r);
        // total number of inversions while merging
        inv_count += merge(arr, l, mid, r);
    }
    return inv_count;
}

int main()
{
    int arr[] = {3, 5, 6, 9, 1, 2, 7, 8};
    cout << mergeSort(arr, 0, 7)<<endl;
    return 0;
}