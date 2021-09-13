#include<iostream>
#include<climits>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void dnfSort(int arr[], int n){
    int low = 0, mid = 0, high = n-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        // i.e arr[mid] == 2
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    int arr[] = {1, 0, 2, 1, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    dnfSort(arr, n);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}