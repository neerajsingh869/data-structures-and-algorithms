#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    // Making a constructor
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
public:
    // Enqueue(x) => Very similar to insertionAtTail() with some modifications
    void enqueue(node *&front, node *&back, int val)
    {
        // Memory allocation in heap
        node *newBack = new node(val);
        if (front == NULL)
        {
            front = newBack;
            back = newBack;
            return;
        }
        back->next = newBack;
        back = newBack;
    }
    // Dequeue() => Very similar to deletionAtHead()
    void dequeue(node *&front, node *&back)
    {
        if (isEmpty(front, back))
        {
            cout << "Nothing to dequeue" << endl;
            return;
        }
        node *toDelete = front;
        front = front->next;
        delete toDelete;
    }
    // Peek() => Very similar to top()
    int peek(node *front, node *back)
    {
        if (isEmpty(front, back))
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    // Empty() => Very similar to empty()
    bool isEmpty(node *front, node *back)
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    node *front = NULL;
    node *back = NULL;
    queue q;
    q.enqueue(front, back, 1);
    q.enqueue(front, back, 2);
    q.enqueue(front, back, 3);
    q.enqueue(front, back, 5);
    cout << q.peek(front, back) << endl;
    q.dequeue(front, back);
    cout << q.peek(front, back) << endl;
    q.dequeue(front, back);
    cout << q.peek(front, back) << endl;
    q.dequeue(front, back);
    cout << q.peek(front, back) << endl;
    q.dequeue(front, back);
    cout << q.isEmpty(front, back) << endl;
    return 0;
}