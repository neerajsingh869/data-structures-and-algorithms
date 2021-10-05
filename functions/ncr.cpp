#include<iostream>
using namespace std;

int fact(int num){
    int factorial = 1;
    for(int i = 2; i<=num; i++){
        factorial = factorial*i;
    }
    return factorial;
}

int nCr(int n, int r){
    // To handle bad inputs.
    if(n<r){
        return -1;
    }
    return fact(n)/(fact(n-r)*fact(r));
}

int main(){
    int n, r;
    cin>>n>>r;
    cout<<nCr(n, r);
    return 0;
}