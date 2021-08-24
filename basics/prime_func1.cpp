#include<iostream>
#include<cmath>
using namespace std;

// Create a function to print prime numbers
int all_prime(int a1, int a2){
    for(int i=a1; i<=a2; i++){
        bool flag = 0;
        for(int j=2; j<=sqrt(i); j++){
            if(i%j == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<i<<endl;
        }
    }
    return 0;
}

int main(){
    // Take two numbers and then make a function to print all the prime numbers between them
    int a, b;
    cin>>a>>b;
    all_prime(a,b);
    return 0;
}

