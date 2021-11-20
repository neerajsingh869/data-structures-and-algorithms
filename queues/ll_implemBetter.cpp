#include<iostream>
using namespace std;

// Template/blueprint for node types
class node{
public:
    int data;
    node* next;
    // Parameterised constructor
    node(int val){
        data = val;
        next = NULL;
    }
};

// Template/blueprint for queue types
class queue{
    node* front;
    node* back;
public:
    // default constructor
    queue(){
        front = NULL;
        back = NULL;
    }
    // Adding elements at the back of the queue
    void enqueue(int val){
        /* Dynammically allocated element of node data type in heap
        and storing its address using newBack pointer in stack*/
        node* newBack = new node(val);
        // When there is nothing in the queue
        if(front == NULL){
            front = newBack;
            back = newBack;
            return ;
        }
        // else
        back->next = newBack;
        back = newBack;
    }
    // Deleting elements from the front of the queue
    void dequeue(){
        if(isEmpty()){
            // There is nothing to dequeue
            cout<<"Nothing to dequeue"<<endl;
            return ;
        }
        node* toDelete = front;
        front = front->next;
        delete toDelete;
    }
    // To get the top element of the queue
    int peek(){
        if(isEmpty()){
            cout<<"Nothing to peek. The queue is empty."<<endl;
            return -1;
        }
        return front->data;
    }
    // To check whether the queue is empty or not.
    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(7);
    cout<<"Current top data: "<<q.peek()<<endl;
    q.dequeue();
    cout << "Current top data: " << q.peek() << endl;
    q.dequeue();
    cout << "Current top data: " << q.peek() << endl;
    q.dequeue();
    cout << "Current top data: " << q.peek() << endl;
    q.dequeue();
    if(q.isEmpty()){
        cout<<"The queue is empty."<<endl;
    }
    else{
        cout<<"The queue is not empty."<<endl;
    }
    return 0;
}