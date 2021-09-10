#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    getline(cin, str);

    // sort(str.begin(), str.end());
    // string ans;
    // for (int i = str.size() - 1; i >= 0; i--){
    //     ans.push_back(str[i]);
    // }
    // cout<<ans<<endl;

    sort(str.begin(), str.end(), greater<int>());
    cout<<str<<endl;
    return 0;
}