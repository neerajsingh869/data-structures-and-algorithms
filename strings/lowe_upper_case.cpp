#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    int diff = 'A' - 'a';
    // to UpperCase Conversion
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] += diff;
        }
    }
    cout << str << endl;
    // to LowerCase Conversion
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] -= diff;
        }
    }
    cout<<str<<endl;
    return 0;
}