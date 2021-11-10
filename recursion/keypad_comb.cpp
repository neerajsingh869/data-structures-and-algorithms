#include<iostream>
#include<string>
using namespace std;

string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    string code = keypadArr[ch - '0'];
    for(int i = 0; i<code.length(); i++){
        keypad(str.substr(1), ans+code[i]);
    }
}

int main(){
    keypad("23", "");
    return 0;
}