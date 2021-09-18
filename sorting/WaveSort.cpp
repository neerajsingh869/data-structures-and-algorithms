#include<iostream>
#include<algorithm>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

// Wave Sort algorithm
void waveSort(int arr[], int n){
    int i = 1;
    while(i<n){
        /* Swap if the current odd positioned element
        is greater than previous even element */
        if(arr[i]>arr[i-1]){
            swap(arr[i], arr[i-1]);
        }
        /* Swap if the current odd positioned element
        is greater than next even element */
        if(arr[i] > arr[i+1] && i < n-1){
            swap(arr[i], arr[i+1]);
        }
        i+=2;
    }
}

int main(){
    int arr[] = {3, 6, 5, 10, 7, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    waveSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}