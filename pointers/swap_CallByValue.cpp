#include<iostream>
using namespace std;

void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << a << " " << b;
}

int main(){
    int a=2;
    int b=4;
    swap(a, b);

    return 0;
}