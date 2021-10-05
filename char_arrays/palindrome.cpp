#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char arr[n+1];
    cin>>arr;

    bool isPalindrome = true;
    int i = 0;
    while(i<=n-i-1){
        if(arr[i] != arr[n-i-1]){
            cout<<"Not Palindrome.";
            isPalindrome = false;
            break;
        }
        i++;
    }
    if(isPalindrome){
        cout<<"Palindrome";
    }
    return 0;
}