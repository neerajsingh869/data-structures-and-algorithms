#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> st;

public:
    // Adding element in the queue -> O(1)
    void enqueue(int val)
    {
        st.push(val);
    }
    // Removing element from the queue and returning top-> O(n)
    int dequeue()
    {   
        // if empty, then print error
        if(st.empty()){
            cout<<"Queue is empty! Nothing to dequeue"<<endl;
            return -1;
        }
        int x = st.top();
        st.pop();
        // If only one element, then return it
        if(st.empty()){
            return x;
        }
        // For other cases
        // res -> stores the bottom most element of the stack
        int res = dequeue();
        // rest will not be included, hence dequeued. Rest 
        // elements will be added to the queue in same order.
        st.push(x);
        // In last, bottom most elements will be returned.
        return res;
    }
    // Queue is empty or not -> O(1)
    bool isEmpty()
    {
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Current top element: " << q.dequeue()<< endl;
    q.enqueue(5);
    q.enqueue(7);
    cout << "Current top element: " << q.dequeue() << endl;
    cout << "Current top element: " << q.dequeue() << endl;
    if (q.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }
    cout << "Current top element: " << q.dequeue() << endl;
    cout << "Current top element: " << q.dequeue() << endl;
    if (q.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }
    return 0;
}
