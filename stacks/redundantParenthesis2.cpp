#include <iostream>
#include <stack>
using namespace std;

bool redundantParenthesis(string str)
{
    // create a stack of characters
    stack<char> st;
    // assuming no redundant Parenthesis
    bool flag = false;
    // traversing all the characters in expression
    for (int i = 0; i < str.length(); i++)
    {
        // if the character is '('
        if(str[i] == '('){
            st.push(str[i]);
        }
        // if the character is operator
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            st.push(str[i]);
        }
        // if the character is operand
        else if((str[i] >='a' && str[i]<='z')||(str[i] >='A' && str[i]<='Z')){
            continue;
        }
        // if the character is ')'
        else{
            /* If the top is '(', then that is the
            case of having redundant parenthesis */     
            if(st.top() == '('){
                flag = true;
                return flag;
            }
            // In other cases, there will be operators in the stack
            while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                st.pop();
            }
            // removing the '('
            st.pop();
        }
    }   
    return flag;
}

int main()
{
    string exp;
    // since ther are no white spaces, I can use cin
    cin >> exp;
    cout << redundantParenthesis(exp) << endl;
    return 0;
}
// Inputs
// (a+(b)/c) -> 1
// ((a+b)) -> 1
// (a+(a+b)) -> 0
// (a+b*(c-d)) -> 0