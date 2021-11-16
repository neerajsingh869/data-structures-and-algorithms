#include <iostream>
using namespace std;

// Blueprint of object of type node
class node
{
public:
    int data;
    node *next;
    // Constructor
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class singlyLinkedList : public node
{
public:
    // Insertion at tail
    // Modify the linked list at the original address -> Call by reference
    void insertAtTail(node *&head, int val)
    {
        // Allocate some memeory in heap space and create node
        node *tail = new node(val);

        if (head == NULL)
        {
            head = tail;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // At the end of the while, we reached the tail node. Now insertion tooks place.
        temp->next = tail;
    }

    // Finding lenght of linked list
    int length(node* head){
        node* temp = head;
        int count = 0;
        while(temp!= NULL){
            temp  = temp->next;
            count++;
        }
        return count;
    }

    // Intersecting two linked list
    void intersect(node* &head1, node* &head2, int pos){
        // We are intersecting linked list 2 at the position pos of linked list 1.
        node* temp1 = head1;    // Bigger one
        node* temp2 = head2;    // Smarter one
        int count = 1;
        while(count!=pos){
            temp1 = temp1->next;
            count++;
        }
        while(temp2->next!=NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1; 
    }

    // Finding intersection point of two linked lists (Call by value since we don't want to do any modifications)
    int intersectingNodeBrute(node* head1, node* head2){
        node* temp1 = head1;
        while(temp1 != NULL){
            node* temp2 = head2;
            while(temp2 != NULL){
                if (temp2->data == temp1->data){
                    return temp2->data;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return -1;
    }

    // Finding intersection point of two linked lists (Call by value since we don't want to do any modifications)
    int intersectingNodeOptim(node* head1, node* head2){
        int n1 = length(head1);
        int n2 = length(head2);
        node* temp1;
        node* temp2;
        int m;
        if(n1>n2){
            temp1 = head1;
            temp2 = head2;
            m = n1-n2;
        }
        else{
            temp1 = head2;
            temp2 = head1;
            m = n2 - n1;
        }
        int count = 0;
        while(count!=m){
            temp1 = temp1->next; 
            if(temp1==NULL){
                return -1;
            }
            count++;
        }
        while(temp2!= NULL && temp1!=NULL){
            if(temp1->data == temp2->data){
                return temp1->data;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return -1;
    }

    // Display the elements
    // Call by value -> Since we don't need to modify the linked list
    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    // first linked list
    node *head1 = NULL;
    singlyLinkedList *d;
    d->insertAtTail(head1, 1);
    d->insertAtTail(head1, 2);
    d->insertAtTail(head1, 6);
    d->insertAtTail(head1, 12);
    d->insertAtTail(head1, 18);
    d->insertAtTail(head1, 22);
    d->insertAtTail(head1, 30);
    d->display(head1);

    // second linked list
    node *head2 = NULL;
    d->insertAtTail(head2, 5);
    d->insertAtTail(head2, 10);
    d->insertAtTail(head2, 22);
    d->insertAtTail(head2, 30);
    d->display(head2);
    cout<<d->intersectingNodeOptim(head1, head2)<<endl;

    // Automated way of intersecting two linked lists
    node* head3 = NULL;
    d->insertAtTail(head3, 5);
    d->insertAtTail(head3, 10);
    d->intersect(head1, head3, 4);
    d->display(head1);
    d->display(head3);
    cout << d->intersectingNodeOptim(head1, head3) << endl;
    return 0;
}