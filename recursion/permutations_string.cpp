#include<iostream>
#include<string>
using namespace std;

void permutation(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    for(int i= 0; i<str.length(); i++){
        char fix = str[i];
        string ros = str.substr(0, i) + str.substr(i+1);
        permutation(ros, ans+fix);
    }

}

int main(){
    string str = "ABC";
    permutation(str, "");
    return 0;
}