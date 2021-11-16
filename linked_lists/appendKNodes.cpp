#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    // Constructor
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class doublyLinkedList : public node
{
public:
    // Inserting at head (Call by reference -> For modification)
    void insertAtHead(node *&head, int val)
    {
        node *newHead = new node(val);
        // // if head is null, then this will give me error
        // head -> prev = newHead;
        if (head != NULL)
        {
            head->prev = newHead;
        }
        newHead->next = head;
        head = newHead;
    }

    // Inserting at tail (Call by Reference -> For modification)
    void insertAtTail(node *&head, int val)
    {
        // Allocate memory in Heap
        node *tail = new node(val);
        if (head == NULL)
        {
            // // tail becomes head
            // head = tail;
            // or call insertAtHead method
            insertAtHead(head, val);
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = tail;
        tail->prev = temp;
    }

    // Deletion (Call by Reference -> modification)
    void deletion(node *&head, int pos)
    {
        node *temp = head;
        int count = 1;
        while (temp != NULL)
        {
            if (count == pos)
            {
                break;
            }
            // Update Iterator
            temp = temp->next;
            // Increase count
            count++;
        }
        // Deletion at head
        if (temp == head)
        {
            temp->next->prev = NULL;
            head = temp->next;
            delete temp;
            return;
        }
        // Deletion at tail
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            delete temp;
            return;
        }
        // Deletion at other place
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // Appending last K Nodes to the start (Brute Force). Call by reference because we want to do modifications
    void appendKNodesBrute(node *&head, int k){
        int count = 1;
        while(count<=k){
            node *temp = head;
            while(temp->next!= NULL){
                temp = temp->next;
            }
            temp -> next = head;
            temp -> prev -> next = NULL;
            temp -> prev = NULL;
            head -> prev = temp;
            // Making temp, new head
            head = temp;
            count++;
        }
    }

    // For getting total number of nodes in the doubly linked list
    int totalNodes(node *head){
        node *temp = head;
        int count = 0;
        while(temp!= NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }

    // Appending last K Nodes to the start (Optimized method). Call by reference because we want to do modifications
    void appendKNodesOptim(node *&head, int k){
        node *temp = head;
        node *newTail;
        node *newHead;
        node *tail;
        int n = totalNodes(temp);
        // if k>n
        k = k%n;
        int count = 1;
        while(temp->next != NULL){
            if(count == n-k){
                newTail = temp;
            }
            if(count == n-k+1){
                newHead = temp;
            }
            temp = temp->next;
            count++;
        }
        tail = temp;
        // Main procedure to append K nodes
        // Joining tail with head
        tail->next = head;
        head->prev = tail;
        // Making newHead, head and newTail, tail
        newTail->next = NULL;
        newHead->prev = NULL;
        head = newHead;
        tail = newTail;
    }

    // Display all the nodes of the doubly linked List (Call by Value)
    void display(node *head)
    {
        node *temp = head;
        cout << "NULL"
             << "->";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            // Iterator
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    // Initial value of head is NULL because there are no nodes
    node *head = NULL;
    doublyLinkedList *d;
    d->insertAtTail(head, 1);
    d->insertAtTail(head, 2);
    d->insertAtTail(head, 3);
    d->insertAtTail(head, 4);
    d->insertAtTail(head, 5);
    d->insertAtTail(head, 6);
    d->insertAtTail(head, 7);
    d->insertAtHead(head, 0);
    // d->deletion(head, 2);
    // d->deletion(head, 1);
    d->appendKNodesOptim(head, 4);
    d->display(head);
    return 0;
}