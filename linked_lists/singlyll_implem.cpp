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

class singlyLinkedList:public node{
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

    // Deletion of node at loaction other than head and tail
    void deletion(node *&head, int val)
    {
        node *temp = head;
        // if there are no nodes
        if (head == NULL)
        {
            return;
        }
        // if there is only one node
        if (head->next == NULL)
        {
            deleteAtHead(head);
            return;
        }
        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        node *toDelete = temp->next;
        temp->next = temp->next->next;
        // Deallocating memory from the heap
        delete toDelete;
        // Deleting from the stack also.
        toDelete = NULL;
    }

    // Deletion of node at head
    void deleteAtHead(node *&head)
    {
        node *temp = head;
        head = temp->next;
        delete temp;
        temp = NULL;
    }
    // Deletion of node at tail
    void deleteAtTail(node *&head)
    {
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
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

    // Searching any elements
    bool search(node *head, int key)
    {
        node *temp = head;
        bool flag = false;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                flag = true;
                return flag;
            }
            temp = temp->next;
        }
        return flag;
    }
};

int main()
{
    node *head = NULL;
    /*You can also make a simple object of singlyLinkedList, but
    for that you need to first remove : public node from the class
    def */
    singlyLinkedList *d;
    d->insertAtTail(head, 1);
    d->insertAtTail(head, 2);
    d->insertAtTail(head, 22);
    d->insertAtHead(head, 12);
    d->insertAtTail(head, 30);
    d->display(head);
    d->deletion(head, 1);
    d->display(head);
    d->deleteAtHead(head);
    d->display(head);
    d->deleteAtTail(head);
    d->display(head);
    // cout<<head -> search(head, 2);
    return 0;
}