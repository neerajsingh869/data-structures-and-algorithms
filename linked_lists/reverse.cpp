#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    // constructor
    node(int val){
        data = val;
        next = NULL;
    }

    // Insertion at head
    void insertAtHead(node *&head, int val){
        node *newHead = new node(val);
        newHead -> next = head;
        head = newHead;
    }

    // Reverse the linked list (Iterative Way)
    node* reverseIter(node *&head){
        node *previous = head;
        node *current = head-> next;
        while(current != NULL){
            previous -> next = current -> next;
            current -> next = head;
            head = current;
            current = previous -> next;
        }
        return head;
    }

    // Reverse the linked list (Recursive way)
    node* reverseRecur(node *&head){
        if(head->next == NULL || head == NULL){
            return head;
        }
        node *newHead = reverseRecur(head->next);
        head->next->next= head;
        head->next = NULL;
        return newHead;    
    }

    // Display all the nodes
    void display(node *head){
        node *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            // iterator
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    node *head = NULL;
    head->insertAtHead(head, 3);
    head -> insertAtHead(head, 2);
    head -> insertAtHead(head, 1);
    head -> display(head);
    // node* newHead = head -> reverseIter(head);
    node *newHead = head->reverseIter(head);
    newHead->display(newHead);
    return 0;
}