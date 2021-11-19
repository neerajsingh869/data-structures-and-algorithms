#include<iostream>
#include<stack>
using namespace std;
// Calling by reference (because we want to do modification in original stack)
void insertAtBottom(stack<int> &st, int ele){
    // Base case
    if(st.empty()){
        st.push(ele);
        return;
    }
    int top_ele = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(top_ele);
}

// Calling by reference (because we want to do modification in original stack)
void reverse(stack<int> &st){
    // Base case
    if(st.empty()){
        return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, ele);
}

void display(stack<int> st){
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    display(st);
    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}