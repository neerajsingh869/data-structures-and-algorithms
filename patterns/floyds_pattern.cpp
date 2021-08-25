#include<iostream>
using namespace std;

int main(){
    // Floyd's Pattern
    int n;
    cin>>n;
    int count = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<count+1<<" ";
            count = count + 1;
        }
        cout<<endl;
    }
    return 0;
}