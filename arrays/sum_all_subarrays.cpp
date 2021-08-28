#include<iostream>
using namespace std;

void sum_all_subarray(int arr[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            count += 1;
            cout << "The sum of " << count << "th subarray is: " << sum << endl;
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
    sum_all_subarray(arr, n);

    return 0;
}