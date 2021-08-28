#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        int max = INT_MIN;
        int j;
        for(j=0; j<=i; j++){
            if(arr[j]>max){
                max = arr[j];
            }
        }
        cout<<"Max till "<<i<<":"<<max<<endl;
    }
    return 0;
}