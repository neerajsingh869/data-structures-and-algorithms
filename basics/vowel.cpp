#include<iostream>
#include<typeinfo>
using namespace std;

int main(){
    char c;
    cin>>c;
    bool islowercase, isuppercase;
    islowercase = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    isuppercase = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    if(islowercase || isuppercase){
        cout<<"vowel"<<endl;
    }
    else
    {
        cout<<"consonent"<<endl;
    }
    
    return 0;
}