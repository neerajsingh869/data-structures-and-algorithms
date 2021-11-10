#include<iostream>
#include<string>
using namespace std;

void replace_pi(string str){
    if(str.size() == 0){
        return;
    }
    if(str[0]=='p' && str[1] == 'i'){
        cout<<"3.15";
        string ros = str.substr(2);
        replace_pi(ros);
    }
    else{
        cout<<str[0];
        string ros = str.substr(1);
        replace_pi(ros);
    }
}

int main(){
    string str;
    cin>>str;
    replace_pi(str);
    return 0;
}