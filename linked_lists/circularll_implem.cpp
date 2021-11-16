#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    // Making constructor
    node(int val){
        data=val;
        next = NULL;
    }
};

class circularLinkedList : public node{
public:
    // Insertion at head
    void insertAtHead(node *&head, int val)
    {
        node *newHead = new node(val);
        if (head == NULL)
        {
            newHead->next = newHead;
            head = newHead;
            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newHead->next = head;
        head = newHead;
        temp->next = head;
    }
    // Insert at tail ( Call by Reference -> need to do modification )
    void insertAtTail(node* &head, int val){
        node* temp = head;
        node* tail = new node(val);
        if(head == NULL){
            tail->next= tail;
            head = tail;
            return;
        }
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = tail;
        tail->next = head;        
    }
    // Deletion
    void deletion(node* &head, int pos){
        node* temp = head;
        // Deletion at head
        if (pos == 1)
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }
            node *toDelete = temp->next;
            temp->next = head->next;
            head = head->next;
            delete toDelete;
            return;
        }
        int count = 1;
        while(count!=pos-1){
            temp = temp->next;
            count++;
        }
        // Deletion at middle and tail node
        // You need to store the address of the node which you have to delete in the last
        node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;


    }
    // Displaying the elements of circular linked list
    void display(node* head){
        node* temp = head;
        do{
            cout<<temp->data<<"->";
            temp = temp->next;
        }while(temp!=head);
        cout<<temp->data<<endl;
    }

};

int main(){
    node* head = NULL;
    circularLinkedList* d;
    d->insertAtTail(head, 1);
    d->insertAtTail(head, 2);
    d->insertAtTail(head, 3);
    d->insertAtTail(head, 4);
    d->insertAtTail(head, 5);
    d->insertAtTail(head, 6);
    d->insertAtHead(head, 0);
    d->display(head);
    d->deletion(head, 3);
    d->display(head);
    d->deletion(head, 6);
    d->display(head);
    d->deletion(head, 1);
    d->display(head);
    return 0;
}