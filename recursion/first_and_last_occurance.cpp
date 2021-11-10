#include<iostream>
#include<climits>
using namespace std;

int first_occur(int arr[], int n, int m, int k){
    if(m == n){
        return -1;
    }
    if(arr[m] == k){
        return m;
    }
    return first_occur(arr, n, m+1, k);
}

int last_occur(int arr[], int n, int m, int k){
    if(n == m){
        return -1;
    }
    int rest_occur = last_occur(arr, n, m+1, k);
    if(rest_occur != -1){
        return rest_occur;
    }
    if(arr[m] == k){
        return m;
    }
    return -1;
}

int p = 0, recur1_min = INT_MAX, recur1_max = INT_MIN;
void method_recur1(int arr[], int n, int k){
    if(n == 0){
        cout << recur1_min << " " << recur1_max << endl;
        return;
    }
    if(arr[0] == k){
        recur1_min = min(recur1_min, p);
        recur1_max = max(recur1_max, p);
    }
    p++;
    method_recur1(arr+1, n-1, k);
}

void method_iter(int arr[], int n, int k){
    int max_idx = INT_MIN, min_idx = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            min_idx = min(min_idx, i);
            max_idx = max(max_idx, i);
        }
    }
    cout<<min_idx<<" "<<max_idx<<endl;
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }
    int m = 0;
    // method_recur1(arr, n, k);
    cout<<first_occur(arr, n, m, k)<<" "<<last_occur(arr, n, m, k)<<endl;
    return 0;
}