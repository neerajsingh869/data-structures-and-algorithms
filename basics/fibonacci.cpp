#include<iostream>
using namespace std;

void fib(int num){
    int t1= 0;
    int t2=1;
    for(int i=1; i<=num; i++){
        if(i==1){
            cout<<"Term 1 is:"<<t1<<endl;
        }
        else if(i==2){
            cout<<"Term 2 is:"<<t2<<endl;
        }
        else{
            t1 = t2+t1;
            cout<<"Term "<<i<<"is:"<<t1<<endl;
            int c=t2;
            t2=t1;
            t1=c;
        }
    }
}

int main(){
    int n;
    cin>>n;
    fib(n);
    return 0;
}