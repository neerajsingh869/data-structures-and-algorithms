#include<bits/stdc++.h>
using namespace std;

void sum_brute_force(int arr[], int n, int s){
    // Brute Force -> Time complexity is O(n^2)
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += arr[j];
            if(sum == s){
                cout<<i+1<<" "<<j+1<<endl;
                return;
            }
        }

    }
}

void sum_optimised(int arr[], int n, int s){
    int i = 0, j = 0, st = -1, en = -1, sum = 0;
    while(j<n && sum + arr[j] <= s){
        sum += arr[j];
        j++;
    }
    if(sum == s){
        cout<<i+1<<" "<<j<<endl;
        return;
    }
    while(j<n){
        sum += arr[j];
        while(sum > s){
            sum -= arr[i];
            i++;
        }
        if(sum == s){
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en<<endl;
}

int main(){
    int n, s;
    cin>>n>>s;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    sum_optimised(arr, n, s);
    return 0;
}