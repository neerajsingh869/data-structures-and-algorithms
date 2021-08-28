#include <bits/stdc++.h>
using namespace std;

void record_breaker(int arr[], int n){
    int count_record = 0;
    int maxi = arr[0];
    if(arr[0] > arr[1]){
        count_record+=1;
    }
    for(int i=1; i<n; i++){    
        if(i<n-1){
            if ((arr[i] > maxi) && (arr[i] > arr[i+1]))
            {
                count_record+=1;
            }
        } 
        else{
            if(arr[i] > maxi){
                count_record+=1;
            }
        }
        // cout << count_record << " " << maxi << endl;
        maxi = max(maxi, arr[i]);
        
    }
    cout<<count_record;
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
    record_breaker(arr, n);

    return 0;
}