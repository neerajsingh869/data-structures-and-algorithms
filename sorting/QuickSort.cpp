#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r){
    // Picking last element as pivot
    int pivot = arr[r];
    int i = l-1;
    for(int j = l; j<r; j++){
        if(arr[j] < pivot){
            i++;
            // Here we are passing arr in swap, because it works like a pointer.
            // swap(arr, i, j);
            swap(&arr[i], &arr[j]);
        }
    }
    // i will point to the last smaller element wrt to pivot
    // swap(arr, i+1, r);
    swap(&arr[i+1], &arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r){
    if(l<r){
        int pi = partition(arr, l, r);

        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main(){
    int arr[] = {6,3,9,5,2,8,7};
    quickSort(arr, 0, 6);
    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}