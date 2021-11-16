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
    // Insertion at head
    void insertAtHead(node *&head, int val)
    {
        node *newHead = new node(val);
        newHead->next = head;
        head = newHead;
    }

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
    // Putting even position nodes after odd position nodes
    void evenAfterOdd(node* &head){
        if(head->next == NULL){
            return;
        }
        node* odd = head;
        node* even = head->next;
        while(even->next != NULL && odd->next != NULL){
            node* even_beg = odd->next;
            odd->next = even->next;
            even->next = odd->next->next;
            odd->next->next = even_beg;            
            even = even->next;
            if (even == NULL){
                break;
            }
            odd = odd->next;
            if (odd == NULL)
            {
                break;
            }
        }
    }
    // Putting even position nodes after odd position nodes (Optimized)
    void evenAfterOddOptim(node* &head){
        node* odd = head;
        node* even = head->next;
        node* even_beg = head->next;
        while(odd->next != NULL && even->next != NULL){
            odd->next = even->next;
            even->next = odd->next->next;

            even = even->next;
            odd = odd->next;
        }
        odd->next = even_beg;
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
    node *head = NULL;
    singlyLinkedList *d;
    d->insertAtTail(head, 1);
    d->insertAtTail(head, 2);
    d->insertAtTail(head, 3);
    d->insertAtTail(head, 4);
    d->insertAtTail(head, 5);
    d->insertAtTail(head, 6);
    d->display(head);
    d->evenAfterOddOptim(head);
    d->display(head);
    return 0;
}