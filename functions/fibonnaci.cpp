#include<iostream>
using namespace std;

void fib(int num){
    if(num==1){
        cout<<"0 ";
    }
    else if(num==2){
        cout<<"1 ";
    }
    else{
        int first_num = 0;
        int second_num = 1;
        cout<<first_num<<" "<<second_num<<" ";
        int new_second;
        for(int i=3; i<=num; i++){
            new_second = first_num + second_num;
            cout<<new_second<<" ";
            first_num = second_num;
            second_num = new_second;
        }
    }
    // Since the function type is void, therefore we are not returning anything.
    // If the func type is void, then we can drop return statement.
    return;
}

int main(){
    int n;
    cout<<"Enter a number > 0: ";
    cin>>n;
    fib(n);
    return 0;
}