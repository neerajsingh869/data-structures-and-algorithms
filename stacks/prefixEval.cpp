#include<iostream>
#include<string>
#include<stack>
#include<math.h>
using namespace std;

int prefixEval(string exp){
    stack<int> st;
    // Traversing the elements of exp from right to left
    for(int i=exp.length()-1; i>=0; i--){
        // if the element is operand
        if(exp[i] >= '0' && exp[i] <= '9'){
            // pushing in the stack as interger value
            st.push(exp[i]-'0');
        }
        else{
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();
            switch (exp[i])
            {
            case '+':
                st.push(operand1+operand2);
                break;
            case '-':
                st.push(operand1 - operand2);
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand1 / operand2);
                break;
            case '^':
                st.push(pow(operand1,operand2));
                break;
            }
        }
    }
    return st.top();
}

int main(){
    // prefix expression is input
    string exp;
    // Without any spaces (=> no need of getline)
    cin>>exp;
    cout<<prefixEval(exp)<<endl;
    return 0;
}

// "-+7*45+20" -> Ans = 25