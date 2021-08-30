#include<iostream>
using namespace std;

// In Bubble sort, we repetedly swap two adjacent elements if they are in wrong order. 
// Total iterations required = n-1
void bubble_sort(int arr[], int n){
    int e=n;
    for(int i=1; i<e; i++){
        for(int j=0; j<e-i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        } 
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
    bubble_sort(arr, n);
    return 0;
}