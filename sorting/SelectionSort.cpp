#include<iostream>
using namespace std;

// In Selection sort, there will be two subarrays. Sorted subarray and unsorted subarray. Then you find the min element in the unsorted array and swap it with elment at the beginning of unsorted subarray.
void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min_index = i;
        for(int j=i + 1; j<n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    selection_sort(arr, n);
    return 0;
}