#include<bits/stdc++.h>
using namespace std;

void subseq(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    // Not adding anything to the answer
    subseq(str.substr(1), ans);
    // Adding to the answer
    subseq(str.substr(1), ans + str[0]);
}

int main(){
    string str;
    cin>>str;
    subseq(str, "");
    return 0;
}