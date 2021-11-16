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

class singlyLinkedList
{
    node* head;
public:
    singlyLinkedList(){
        head = NULL;
    }
    /* Here, everything is going to be called by reference.
    So, don't forget to make a temp pointer to store head*/
    // Insertion at head
    void insertAtHead(int val)
    {
        node *newHead = new node(val);
        newHead->next = head;
        head = newHead;
    }

    // Insertion at tail
    void insertAtTail(int val)
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
    void deletion(int val)
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
            deleteAtHead();
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
    void deleteAtHead()
    {
        node *temp = head;
        head = temp->next;
        delete temp;
        temp = NULL;
    }
    // Deletion of node at tail
    void deleteAtTail()
    {
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
    // Display the elements (Remember everything is happenning by call by reference)
    void display()
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
    bool search(int key)
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
    singlyLinkedList d;
    d.insertAtTail(1);
    d.insertAtTail(2);
    d.insertAtTail(22);
    d.insertAtHead(12);
    d.insertAtTail(30);
    d.display();
    d.deletion(1);
    d.display();
    d.deleteAtHead();
    d.display();
    d.deleteAtTail();
    d.display();
    // cout<<head -> search(head, 2);
    return 0;
}