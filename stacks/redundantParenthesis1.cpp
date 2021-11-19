#include<iostream>
#include<stack>
using namespace std;

bool redundantParenthesis(string str){
    // create a stack of characters
    stack<char> st;
    // assuming no redundant Parenthesis
    bool flag = false;
    // traversing all the characters in expression
    for(int i=0; i<str.length(); i++){
        // If current character is ')'
        if(str[i] == ')'){
            // Assuming no operator between parenthesis
            bool oper = false;
            // CONDITION 1
            /* If the top is '(', then that is the
            case of having redundant parenthesis */
            if(st.top() == '('){
                flag = true;
                return flag;
            }
            /* no need to check st.empty() as the
            expression is valid and balanced*/
            while(st.top()!='('){
                if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                    oper = true;
                }
                st.pop();
            }
            st.pop();
            // CONDITION 2
            /* If there is no operator between parenthesis, 
            then that is the case of having redundant Parenthesis */
            if(oper==false){
                return true;
            }
        }
        // if the character is '(', operand or operator
        else{
            st.push(str[i]);
        }   
    }
    return flag;
}

int main(){
    string exp;
    // since ther are no white spaces, I can use cin
    cin>>exp;
    cout<<redundantParenthesis(exp)<<endl;
    return 0;
}
// Inputs
// (a+(b)/c) -> 1
// ((a+b)) -> 1
// (a+(a+b)) -> 0
// (a+b*(c-d)) -> 0