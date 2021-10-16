#include<iostream>
using namespace std;

int main(){
    int i = 5;
    int j = 10;
    int* p = &i;
    // reference must be initialized at the time of declaration
    int& ref = i;
    cout<<ref<<endl;
    // p stores the address of i
    cout<<p<<endl;
    // reference can't be used to refer to another variable
    ref = j;    // Here, the value of i become j. The statement is equivalent to "i=j"
    cout<<i<<endl;
    cout << ref << endl; 
    ref++;
    cout<<ref << endl;
    cout<<j<<endl;
    cout << i << endl;
    return 0;
}