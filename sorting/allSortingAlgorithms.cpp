#include<climits>

// Helper function for Selection Sort
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Can also use this for swapping (Much cleaner)
// void swap(int &x, int &y)
// {
//     int temp = x;
//     x = y;
//     y = temp;
// }

// Selection Sort
void selectionSort(int arr[], int n)
{
    // Total iterations needed = n-1 (Since last element is at the right position)
    // v[0..i-1] is sorted and v[i...n-1] is not sorted
    for (int i = 0; i < n - 1; i++)
    {
        // Finding the minimum element index in v[i...n-1]
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIdx] > arr[j])
            {
                minIdx = j;
            }
        }
        // Now we have the index of minimum element
        // Swap it with the beginning of the unsorted subarray
        swap(&arr[minIdx], &arr[i]);
        // swap(arr[minIdx], arr[i]);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = arr[j + 1];
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int currIdx = i;
        int j;
        /* Finding the index of first element in sorted
        subarray which is just greater than arr[currIdx] */
        for (j = 0; j < i; j++)
        {
            if (arr[j] > arr[currIdx])
            {
                break;
            }
        }
        /* Once we found the index, now we are going to
        shift all elements one place right in order to
        place the arr[currIdx] at the right position */
        int temp = arr[currIdx];
        for (int k = i; k > j; k--)
        {
            arr[k] = arr[k - 1];
        }
        arr[j] = temp;
    }
}

// Helper function for Merge Sort
void merge(int arr[], int start, int mid, int end)
{
    /* TODO: Merge the left and right subarray in right order */
    // Make two temp arrays
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int temp1[n1], temp2[n2];
    for (int i = 0; i < n1; i++)
    {
        temp1[i] = arr[start + i];
    }
    for (int i = 0; i < n2; i++)
    {
        temp2[i] = arr[mid + 1 + i];
    }
    // Merge these two temp arrays together in the original array
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (temp1[i] < temp2[j])
        {
            arr[k] = temp1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = temp2[j];
            k++;
            j++;
        }
    }
    // Assuming temp1 to be larger than temp2
    while (i < n1)
    {
        arr[k] = temp1[i];
        k++;
        i++;
    }
    // Assuming temp2 to be larger than temp1
    while (j < n2)
    {
        arr[k] = temp2[j];
        k++;
        j++;
    }
}

// Merge Sort
void mergeSort(int arr[], int start, int end)
{
    // Base case
    if (start >= end)
    {
        // do nothing
        return;
    }
    int mid = (start + end) / 2;
    // sort arr[start...mid] and sort arr[mid+1...end]
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    // Now merge sorted left and right subarray
    merge(arr, start, mid, end);
}

// Helper function for Quick Sort
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Helper function for Quick Sort
int partition(int arr[], int start, int end)
{
    /* TODO: Choose a pivot element, place it in the correct place
    in the sorted array and put all the smaller element to the left 
    of it and all the larger elements to the right of it. 
    Return the index of the pivot element. */

    // Choosing last element as pivot
    int pivot = arr[end];
    // Place the pivot at right position
    // i is the index of last element less than the pivot
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    /* Now, from start till i index all element are smaller 
    than the pivot element and from i+1 till end-1 index all
    element are larger than the pivot element. So, the correct
    position of pivot element in at i+1 index. */
    swap(arr[i + 1], arr[end]);

    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        // do nothing
        return;
    }
    /* Pick a pivot element, do partitioning around the pivot
    element and return the index of the pivot element */
    int pivotIdx = partition(arr, start, end);
    // quick sort the elements to left of the pivot element
    quickSort(arr, start, pivotIdx - 1);
    // quick sort the elements to right of the pivot element
    quickSort(arr, pivotIdx + 1, end);
}

// Count Sort
void countSort(int arr[], int n)
{
    /* TODO: Sort the given array using Count Sort algorithm
    Assumption: The array has no negative elements*/

    // Finding maximum element
    int maxEle = INT_MIN;
    for (int i = 0; i < n; i++)
    {   
        if(maxEle < arr[i]){
            maxEle = arr[i];
        }
    }
    // Building count array
    int n1 = maxEle + 1;
    int countArr[n1] = {0};
    for (int i = 0; i < n; i++)
    {
        countArr[arr[i]]++;
    }
    // Modifying the count array
    for (int i = 1; i < n1; i++)
    {
        countArr[i] += countArr[i - 1];
    }
    // Sorting the original array and updating the index in countArr
    int sortedArr[n];
    for (int i = n - 1; i >= 0; i--)
    {
        // finding the index of element in sorted order
        int idx = countArr[arr[i]] - 1;
        // updating the index of element in countArr
        countArr[arr[i]] = idx;
        sortedArr[idx] = arr[i];
    }
    // Putting the sorted array in the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = sortedArr[i];
    }
}

// Helper function for DNF Sort
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// DNF Sort
void dnfSort(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        // i.e arr[mid] == 2
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// Helper function for Wave Sort
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Wave Sort
void waveSort(int arr[], int n)
{
    int i = 1;
    while (i < n)
    {
        /* Swap if the current odd positioned element
        is greater than previous even element */
        if (arr[i] > arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
        }
        /* Swap if the current odd positioned element
        is greater than next even element */
        if (arr[i] > arr[i + 1] && i < n - 1)
        {
            swap(arr[i], arr[i + 1]);
        }
        i += 2;
    }
}