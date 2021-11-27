#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> st1;
    stack<int> st2;
public:
    // Adding element in the queue -> O(1)
    void enqueue(int val){
        st1.push(val);
    }
    // Removing element from the queue -> O(n)
    void dequeue(){
        if(st1.empty() && st2.empty()){
            cout<<"Queue is empty! Nothing to dequeue."<<endl;
            return;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        st2.pop();
    }
    // Top element of the queue -> O(n)
    int peek() {
        if(st2.empty() && st1.empty()){
            cout<<"Queue is empty! Nothing to peek."<<endl;
            return -1;
        }
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    // Queue is empty or not -> O(1)
    bool isEmpty(){
        if(st1.empty() && st2.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<"Current top element: "<<q.peek()<<endl;
    q.dequeue();
    cout << "Current top element: " << q.peek() << endl;
    q.enqueue(5);
    q.enqueue(7);
    q.dequeue();
    cout << "Current top element: " << q.peek() << endl;
    q.dequeue();
    cout << "Current top element: " << q.peek() << endl;
    if(q.isEmpty()){
        cout<<"Queue is empty."<<endl;
    }
    else{
        cout<<"Queue is not empty."<<endl;
    }
    q.dequeue();
    cout << "Current top element: " << q.peek() << endl;
    q.dequeue();
    cout << "Current top element: " << q.peek() << endl;
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
