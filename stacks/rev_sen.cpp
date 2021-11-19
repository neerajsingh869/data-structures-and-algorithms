#include<iostream>
#include<stack>
#include<string>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    // Pushing words of the sentence into stack
    for(int i=0; i<s.length(); i++) {
        string word = "";
        while(s[i]!=' ' && i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }
    // Printing the words of sentence in reverse order
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    string s;
    getline(cin, s);
    reverseSentence(s);
    return 0;
}