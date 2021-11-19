#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;

string postfixEval(string exp)
{
    stack<string> st;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] >= 'a' && exp[i] <= 'z')
        {
            st.push(to_string(exp[i]));
        }
        else
        {
            // top element of the stack will be the 2nd operand
            string operand2 = st.top();
            st.pop();
            // 2nd top element of the stack will be the 1st operand
            string operand1 = st.top();
            st.pop();
            st.push('('+operand1+exp[i]+operand2+')');
        }
    }
    return st.top();
}

int main()
{
    string exp;
    cin >> exp;
    cout << postfixEval(exp) << endl;
    return 0;
}
// "abc/-ak/l-*" Output = ((97-(98/99))*((97/107)-108))