#include<iostream>
#include<climits>
using namespace std;

void countSort(int arr[], int n){
    /* TODO: Sort the given array using Count Sort algorithm
    Assumption: The array has no negative elements*/

    // Finding maximum element
    int maxEle = INT_MIN;
    for(int i = 0; i<n; i++){
        maxEle = max(maxEle, arr[i]);
    }
    // Building count array
    int n1 = maxEle+1;
    int countArr[n1] = {0};
    for(int i = 0; i<n; i++){
        countArr[arr[i]]++;
    }
    // Modifying the count array
    for(int i = 1; i<n1; i++){
        countArr[i] += countArr[i-1];
    }
    // Sorting the original array and updating the index in countArr
    int sortedArr[n];
    for(int i = n-1; i>=0; i--){
        // finding the index of element in sorted order
        int idx = countArr[arr[i]] - 1;
        // updating the index of element in countArr
        countArr[arr[i]] = idx;
        sortedArr[idx] = arr[i];
    }
    // Putting the sorted array in the original array
    for(int i = 0; i< n; i++){
        arr[i] = sortedArr[i];
    }
}

int main(){
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    countSort(arr, n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}