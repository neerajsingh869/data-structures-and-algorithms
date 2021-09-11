#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string str;
    cin>>str;
    int count[26];
    for(int i=0; i<26; i++){
        count[i] = 0;
    }
    int max_count = 0;
    string max_char;
    for(int i = 0; i < str.size(); i++){
        count[str[i] - 'a']++;
        if (count[str[i] - 'a'] > max_count)
        {
            max_count = count[str[i] - 'a'];
            max_char = str[i];
        }
    }
    cout<<max_count<<endl<<max_char<<endl;
    return 0;
}