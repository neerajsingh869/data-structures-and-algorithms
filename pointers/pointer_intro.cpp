#include<iostream>
using namespace std;

int main(){
    int a=30;
    int *ap = &a;
    // Equivalent of this - int *ap and then ap = &a
    cout<<ap<<endl;
    cout<<&a<<endl;
    cout<<a<<endl;
    cout<<*ap<<endl;
    // Deferencing: Able to reference to the variable with help of another variable. 
    *ap = 40;
    cout<<a<<endl;
    return 0;
}