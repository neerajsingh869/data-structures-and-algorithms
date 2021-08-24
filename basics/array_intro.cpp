#include<iostream>
using namespace std;

int main(){
    // **1st Manual Way of storing data in array
    // int array[4] = {20, 70, 50, 20};
    // **2nd Manual Way of storing data in array
    // int array[4];
    // array[0] = 20;
    // array[1] = 70;
    // array[2] = 50;
    // array[3] = 10;

    // **Fastest way to store data in array
    int n;
    cin>>n;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << array[i]<<" ";
    }

    
    return 0;
}