#include<iostream>
using namespace std;

// Defined n globally
#define n 100

class stack{
public:
    int *arr;
    int top;
    // Making default constructor
    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top == n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    // Removing the top element
    void pop(){
        if(top == -1){
            cout<<"No element to pop"<<endl;
            return;
        }
        top--;
    }

    int Top(){
        if(top == -1){
            cout<<"No elements in the stack"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        if(top == -1){
            return true;
        }
        return false;
    }
};

int main(){
    stack st;
    st.push(3);
    st.push(5);
    st.push(9);
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    cout<<st.empty()<<endl;
    return 0;
}