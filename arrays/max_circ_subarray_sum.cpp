#include <bits/stdc++.h>
using namespace std;

int sum_array(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int kadane_algorithm(int arr[], int n)
{
    int curr_sum = 0, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
        maxi = max(maxi, curr_sum);
    }
    return maxi;
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
    int rev_array[n];
    for (int i = 0; i < n; i++)
    {
        rev_array[i] = -arr[i];
    }
    int non_wrapup = kadane_algorithm(arr, n);
    int wrapup = sum_array(arr, n) - (-kadane_algorithm(rev_array, n));
    int max_sum = max(wrapup, non_wrapup);
    cout<<max_sum;
    return 0;
}