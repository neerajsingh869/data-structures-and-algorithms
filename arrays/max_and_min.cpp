#include<bits/stdc++.h>
using namespace std;

int main(){
    int arrSize;
    cin>>arrSize;

    // Taking the items of array as an input from the user.
    int arr[arrSize];
    for(int i=0; i<arrSize; i++){
        cin>>arr[i];
    }

    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0; i<arrSize; i++){
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    cout << "Max is: " << maxi << endl
         << "Max is: " <<mini << endl;

    return 0;
}