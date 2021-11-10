#include<iostream>
#include<string>
using namespace std;

string move_x(string str){
    if(str.size() == 0){
        return "";
    }
    if(str[0] != 'x'){
        return str[0] + move_x(str.substr(1));
    }
    else{
        return move_x(str.substr(1)) + str[0];
    }
}

int main(){
    string str;
    // Input string without space
    cin>>str;
    cout<<move_x(str)<<endl;
    return 0;
}
// axxbdxcefxhix