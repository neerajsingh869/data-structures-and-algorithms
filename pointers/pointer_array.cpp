#include<iostream>
using namespace std;

int main(){
    int arr[] = {10, 30, 50};
    cout<<*arr<<endl;
    int *ptr = arr;
    for(int i=0; i<3; i++){
        // 1st Way
        cout<<*(arr+i)<<endl;
        // 2nd Way
        // cout<<*ptr<<endl;
        // ptr++; // If you replace ptr with arr, then there will be an error because you can't perform any arithmetic operations on array just like pointer.
    }
    return 0;
}