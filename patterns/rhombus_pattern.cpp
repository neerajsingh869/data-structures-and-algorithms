#include<iostream>
using namespace std;
int main(){
    // Rhoumbus Pattern
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3*n - 1 - i; j++){
            if((j<=n-i) || ((j+i)%2!=0)){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}