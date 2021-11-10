#include<iostream>
using namespace std;



int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    permutation1(arr, "");
    return 0;
}