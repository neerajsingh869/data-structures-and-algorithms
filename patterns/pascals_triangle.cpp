#include<iostream>
using namespace std;

int fact(int num){
    int t=1;
    if(num==0){
        return t;
    }
    else{
        for(int i=1; i<=num; i++){
        t=t*i;
        }
    }
    
    return t;
}

void pascals_triangle(int num){
    for(int i=1; i<=num; i++){
        for(int j=1; j<=i; j++){
            int element = fact(i-1)/(fact(j-1)*fact(i-j));
            cout<<element<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    pascals_triangle(n);
    return 0;
}