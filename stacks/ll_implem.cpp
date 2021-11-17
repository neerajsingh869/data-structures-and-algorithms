#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    // Making a constructor
    node(int val){
        data=val;
        next=NULL;
    }
};

class stack:public node{
public:
    // push(x) -> O(1) (Similar to insertion at head in linked list)
    void push(node* &head, int val){
        // Memory allocation in heap
        node* newHead = new node(val);
        if(head==NULL){
            head = newHead;
            return;
        }
        newHead->next = head;
        head = newHead;
    }

    // pop() -> O(1) (Similar to deletion at head in linked list)
    void pop(node* &head){
        if(head == NULL){
            return;
        }
        node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    // Top() -> O(1) (Returns the data at head pointer)
    int Top(node* head){
        if(head == NULL){
            cout<<"No element in the stack!"<<endl;
            // -1 will be returned if the stack is empty
            return -1;
        }
        return head->data;
    }

    // empty() -> O(1) (Returns true if the stack is empty and false otherwise)
    bool empty(node* head){
        if(head == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    // Display the elements of stack
    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    node* head = NULL;
    stack *d;
    d->push(head, 3);
    d->push(head, 5);
    d->push(head, 9);
    d->display(head);
    d->pop(head);
    cout<<d->Top(head)<<endl;
    d->pop(head);
    cout << d->Top(head) << endl;
    d->pop(head);
    cout << d->Top(head) << endl;
    cout << d->empty(head) << endl;
    return 0;
}