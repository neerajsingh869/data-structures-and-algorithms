#include<bits/stdc++.h>
using namespace std;

void subseq(string str, string ans){
    if(str.size() == 0){
        cout<<ans<<endl;
        return;
    }
    subseq(str.substr(1), ans);
    subseq(str.substr(1), ans+str[0]);
    // To get ascii code
    int ascii = str[0];
    subseq(str.substr(1), ans+to_string(ascii));
}

int main(){
    string str;
    cin>>str;
    subseq(str, "");
    return 0;
}