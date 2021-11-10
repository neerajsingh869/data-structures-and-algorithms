#include<iostream>
#include<string>
using namespace std;

string revStr(string str, int n){
    if(n<0){
        return "";
    }
    return str[n] + revStr(str, n - 1);
}

int main(){
    string str = "binod";
    int n = str.size();
    cout<<revStr(str, n-1);
    return 0;
}