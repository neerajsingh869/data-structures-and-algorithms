#include<iostream>
// Sort() is present in <algorithm> header file.
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {5, 4, 6, 9, 10, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    // Sorting in ascending order
    sort(arr, arr+n);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Sorting in descending order
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}