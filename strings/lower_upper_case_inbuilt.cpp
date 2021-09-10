#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    // cin>>str;
    // to UpperCase
    transform(str.begin(),str.end(), str.begin(), ::toupper);
    cout<<str<<endl;

    // to LowerCase
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout<<str<<endl;

    return 0;
}