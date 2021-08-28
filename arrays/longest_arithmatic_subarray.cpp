#include<bits/stdc++.h>
using namespace std;

void longst_arith_subary(int arr[], int n){
    // curr -> store the current arithmetic subarray lenght.
    // Since already we have two element.
    int curr = 2;
    int maxi = INT_MIN;
    int old_diff = arr[2] - arr[1];
    for(int i = 2; i < n; i++){
        int curr_diff = arr[i] - arr[i-1];
        if(curr_diff == old_diff){
            curr++;
        }
        else{
            old_diff = curr_diff;
            curr = 2;
        }
        if (curr > maxi)
        {
            // maxi -> store the Max arithmetic subarray lenght.
            maxi = curr;
        }
    }
    cout<<"The length of longest arithmetic subarray is: "<<maxi<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    longst_arith_subary(arr, n);
    return 0;
}