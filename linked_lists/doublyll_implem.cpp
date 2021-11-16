#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* prev;
    // Constructor 
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};


class doublyLinkedList : public node{
public:
    // Inserting at head (Call by reference -> For modification)
    void insertAtHead(node *&head, int val){
        node *newHead = new node(val);
        // // if head is null, then this will give me error
        // head -> prev = newHead;
        if(head != NULL){
            head->prev = newHead;
        }
        newHead -> next = head;
        head = newHead;
    }

    // Inserting at tail (Call by Reference -> For modification)
    void insertAtTail(node* &head, int val){
        // Allocate memory in Heap
        node *tail = new node(val);
        if(head == NULL){
            // // tail becomes head
            // head = tail;
            // or call insertAtHead method
            insertAtHead(head, val);
            return;
        }
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = tail;
        tail->prev = temp;
    }

    // Deletion (Call by Reference -> modification)
    void deletion(node *&head, int pos){
        node *temp = head;
        int count = 1;
        while(temp != NULL){
            if(count == pos){
                break;
            }
            // Update Iterator
            temp = temp->next;
            // Increase count
            count++;
        }
        // Deletion at head
        if(temp == head){
            temp->next->prev = NULL;
            head = temp->next;
            delete temp;
            return;
        }
        // Deletion at tail
        if(temp->next == NULL){
            temp->prev->next = NULL;
            delete temp;
            return;
        }
        // Deletion at other place
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // Display all the nodes of the doubly linked List (Call by Value)
    void display(node *head){
        node* temp = head;
        cout<<"NULL"<<"->";
        while(temp!=NULL){
            cout<<temp->data<<"->";
            // Iterator
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    // Initial value of head is NULL because there are no nodes 
    node* head = NULL;
    doublyLinkedList *d;
    d -> insertAtTail(head, 1);
    d -> insertAtTail(head, 2);
    d -> insertAtTail(head, 3);
    d -> insertAtHead(head, 0);
    d -> deletion(head, 2);
    d -> deletion(head, 1);
    d -> display(head);
    return 0;
}