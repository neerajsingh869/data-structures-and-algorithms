#include<iostream>
using namespace std;

int friends_pair(int n){
    if(n<=0){
        return 0;
    }
    if(n==1 || n==2){
        return n;
    }
    return friends_pair(n-1) + friends_pair(n-2)*(n-1);
}

int main(){
    int friends;
    cin>>friends;
    cout<<friends_pair(friends);
    return 0;
}