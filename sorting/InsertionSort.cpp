#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=1; i<n; i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

// Another way of using insertion sort
void insertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int currIdx = i;
        int j;
        /* Finding the index of first element in sorted
        subarray which is just greater than arr[currIdx] */
        for(j=0; j<i; j++){
            if(arr[j] > arr[currIdx]){
                break;
            }
        }
        /* Once we found the index, now we are going to
        shift all elements one place right in order to
        place the arr[currIdx] at the right position */
        int temp = arr[currIdx];
        for(int k = i; k>j; k--){
            arr[k] = arr[k-1];
        }
        arr[j] = temp;
    }
    }

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    insertion_sort(arr, n);
    return 0;
}