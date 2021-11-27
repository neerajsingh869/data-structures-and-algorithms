#include <iostream>
#include <queue>
using namespace std;

class stack
{
    // N represent the size of the stack
    // int N;

    queue<int> q1;
    queue<int> q2;

public:
    // Making default constructor
    // stack(){
        // Since, Intially the size of the stack is 0
    //     N = 0;
    // }

    // push() function
    void push(int val)
    {
        q1.push(val);
        // N++;
    }
    //  pop() function
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty! Nothing to pop" << endl;
            return;
        }
        while(q1.size() !=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        // swapping q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        // N--;
    }
    // top() function
    int top(){
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        /* q1 should be empty otherwise some residual
        values will be stored in q2 during swapping.*/
        q1.pop();
        // swapping q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }
    // size() function
    int size()
    {
        // return N
        return q1.size();
    }
    // empty() function
    bool isEmpty()
    {
        // if(N==0)
        if (q1.empty())
        {
            return true;
        }
        return false;
    }
};
/*You can also use N but the same things can be done using q1.size() function*/

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << "Size: " << st.size() << endl;
    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Size: " << st.size() << endl;
    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "Size: " << st.size() << endl;
    cout << st.isEmpty() << endl;
    return 0;
}