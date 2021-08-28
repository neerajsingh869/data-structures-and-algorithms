#include<bits/stdc++.h>
using namespace std;

void missing_brute(int arr[], int n){
    // N = max element that can go in arr[]
    int N = 1e5;
    int idx[N];
    for(int i = 0; i < N; i++){
        idx[i] = -1;
    }
    for(int i = 0; i < n; i++){
        if(arr[i] >= 0){
            if (idx[arr[i]] == -1)
            {
                idx[arr[i]] = i;
            }
        }    
    }
    for(int i = 0; i < N; i++){
        if(idx[i] == -1){
            cout<<i<<endl;
            break;
        }
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    missing_brute(arr, n);
    return 0;
}