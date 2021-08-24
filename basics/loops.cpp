#include<iostream>
using namespace std;

int main(){
    int number;
    cout<<"Enter the number:"<<endl;
    cin>>number;
    int sum = 0;
    while(number>=0){
        sum = sum+number;
        cin>>number;
    }
    cout<<sum;
    return 0;
}