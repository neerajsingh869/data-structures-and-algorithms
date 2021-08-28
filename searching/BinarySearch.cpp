#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int key){
    int s=0;
    int e=n-1;
    while(s<=e){
        if(arr[(s+e)/2]==key){
            return (s+e)/2;
        }
        else if(arr[(s+e)/2]>key){
            e = (s+e)/2 - 1;
        }
        else{
            s = (s+e)/2 + 1;
        }
    }
    return -1;

}

int main(){
    int n;
    cin>>n;
    int key;
    cin>>key;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<binary_search(arr, n, key);
    return 0;
}