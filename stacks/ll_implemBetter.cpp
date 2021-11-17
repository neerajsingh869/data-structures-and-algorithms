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

class stack
{
    node* head;
public:
    stack(){
        head = NULL;
    }
    // push(x) -> O(1) (Similar to insertion at head in linked list)
    void push(int val)
    {
        // Memory allocation in heap
        node *newHead = new node(val);
        if (head == NULL)
        {
            head = newHead;
            return;
        }
        newHead->next = head;
        head = newHead;
    }

    // pop() -> O(1) (Similar to deletion at head in linked list)
    void pop()
    {
        if (head == NULL)
        {
            return;
        }
        node *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    // Top() -> O(1) (Returns the data at head pointer)
    int Top()
    {
        if (head == NULL)
        {
            cout << "No element in the stack!" << endl;
            // -1 will be returned if the stack is empty
            return -1;
        }
        return head->data;
    }

    // empty() -> O(1) (Returns true if the stack is empty and false otherwise)
    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Display the elements of stack
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{   
    // This looks beautiful as well as less confusing\
    and less complicated.
    stack d;
    d.push(3);
    d.push(5);
    d.push(9);
    d.display();
    d.pop();
    cout << d.Top() << endl;
    d.pop();
    cout << d.Top() << endl;
    d.pop();
    cout << d.Top() << endl;
    cout << d.empty() << endl;
    return 0;
}