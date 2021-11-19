#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;

int postfixEval(string exp){
    stack<int> st;
    for(int i=0; i<exp.length(); i++){
        if(exp[i]>='0' && exp[i]<='9'){
            st.push(exp[i] - '0');
        }
        else{
            // top element of the stack will be the 2nd operand
            int operand2 = st.top();
            st.pop();
            // 2nd top element of the stack will be the 1st operand
            int operand1 = st.top();
            st.pop();
            switch (exp[i]){
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
    string exp;
    cin>>exp;
    cout<<postfixEval(exp)<<endl;
    return 0;
}
// "46+2/5*7+" Ans = 32