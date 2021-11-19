#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<string> stk;
    stk.push("Hey,");
    stk.push("how");
    stk.push("are");
    stk.push("you");
    stk.push("doing?");
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}