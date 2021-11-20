#include<iostream>
using namespace std;

#define n 100

class queue{
    int *arr;
    int front, back;
public:   
    // Default constructor
    queue(){
        // Dynamically allocation
        arr = new int[n];
        front = -1;
        back = -1;
    }
    // Enqueue(x) function => Similar to push(x)
    void enqueue(int x){
        if(back==n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        if(front==-1){
            front = 0;
        }
        back++;
        arr[back] = x;
    }
    // Dequeue() function => Similar to pop()
    void dequeue(){
        if(isEmpty()){
            cout<<"No elements to dequeue"<<endl;
            return;
        }
        front++;
    }
    // Peek() function => Similar to Top()
    int peek(){
        if(isEmpty()){
            cout<<"No element in queue"<<endl;
            return -1;
        }
        return arr[front];
    }
    // Empty() function => Similar to isEmpty()
    bool isEmpty(){
        if(front == -1 || (front > back)){
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
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    cout << q.peek() << endl;
    cout<<q.isEmpty()<<endl;
    q.dequeue();
    cout << q.peek() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}