#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

string prefixEval(string exp)
{
    stack<string> st;
    // Traversing the elements of exp from right to left
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        // if the element is operand
        if (exp[i] >= 'a' && exp[i] <= 'z')
        {
            // pushing in the stack as interger value
            st.push(to_string(exp[i]));
        }
        else
        {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            st.push('(' + operand1 + exp[i] + operand2 + ')');
        }
    }
    return st.top();
}

int main()
{
    // prefix expression is input
    string exp;
    // Without any spaces (=> no need of getline)
    cin >> exp;
    cout << prefixEval(exp) << endl;
    return 0;
}

// "-+a*bc+de" -> Output = =((97+(98*99))-(100+101))