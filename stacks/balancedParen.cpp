#include<iostream>
#include<stack>
using namespace std;

bool isBalancedParan(string str){
    bool flag = false;
    stack<char> st;
    // Traversing the string
    for(int i = 0; i < str.length();i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            // If the last character is opening brackets, then it is not balanced.
            if(i==str.length()-1){
                flag = false;
                break;
            }
            st.push(str[i]);
        }
        // Assuming there are only brackets in the string
        else{
            /* If we encountered a closing brackets then there must be opening brackets
            at the top of the stack to be balanced. In all other cases, it is not balanced.*/
            if (str[i] == ')')
            {                   
                if (!st.empty() && st.top() == '('){
                    st.pop();
                    if (st.empty() && i == str.length() - 1)
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }

            if (str[i] == ']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                    if (st.empty() && i == str.length() - 1)
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (str[i] == '}')
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                    if (st.empty() && i == str.length() - 1)
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    return flag;
}

int main(){
    string paren;
    cin>>paren;
    // cout<<isBalancedParan(paren)<<endl;
    if(isBalancedParan(paren)){
        cout<<"Balanced Parentheses"<<endl;
    }
    else{
        cout<<"Not Balanced Paentheses"<<endl;
    }
    return 0;
}
// {([])} => Balanced parentheses
// {[(})] => Not balanced parentheses
// {{{{} => Not balanced parentheses