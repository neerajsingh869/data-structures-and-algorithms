#include <bits/stdc++.h>
using namespace std;

// Approach 1
void max_subarray_brute(int arr[], int n)
{   
    int maxi = INT_MIN, si = -1, ei = -1;
    for (int i = 0; i < n; i++)
    {   
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if(sum>maxi){
                maxi = sum;
                si = i;
                ei = j;
            }
        }
    }
    if(si>=0 && ei>=0){
        for (int i = si; i <= ei; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << "Sum is: " << maxi;
    }
    
}

// Approach 2
void max_subarray_prefixSumTechnique(int arr[], int n){
    int cumm_sum[n+1];
    cumm_sum[0] = 0;
    for(int i = 1; i <= n; i++){
        cumm_sum[i] = cumm_sum[i - 1] + arr[i-1];
    }
    int maxi = INT_MIN;
    for(int i=1; i <= n; i++){
        int sum;
        for(int j=0; j<i; j++){
            sum = cumm_sum[i] - cumm_sum[j];
            maxi = max(maxi, sum);
        }
    }
    cout<<maxi<<endl;
}

// Approach 3
void kadane_algorithm(int arr[], int n){
    int curr_sum = 0, maxi = INT_MIN;
    for(int i=0; i<n; i++){
        curr_sum += arr[i];
        if(curr_sum < 0){
            curr_sum = 0;
        }
        maxi = max(maxi, curr_sum);
    }
    cout<<maxi<<endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    kadane_algorithm(arr, n);
    return 0;
}