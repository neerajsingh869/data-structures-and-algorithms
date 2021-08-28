#include<bits/stdc++.h>
using namespace std;



bool pair_sum_brute(int arr[], int n, int k){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] + arr[j] == k){
                cout<<i<<" "<<j<<endl;
                return true;
            }
        }
    }
    return false;
}

bool pair_sum_optimise(int arr[], int n, int k){
    // For this procedure to work, we need a sorted array.
    int si = 0, ei = n-1;
    while(si < ei){
        if (arr[si] + arr[ei] > k)
        {
            ei--;
        }
        else if (arr[si] + arr[ei] < k)
        {
            si++;
        }
        else
        {   
            cout<<si<<" "<<ei<<endl;
            return true;
        }
    }
    return false;
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout << pair_sum_optimise(arr, n, k);
    return 0;
}