#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    // constructor
    node(int val)
    {
        data = val;
        next = NULL;
    }

    // Insertion at head
    void insertAtHead(node *&head, int val)
    {
        node *newHead = new node(val);
        newHead->next = head;
        head = newHead;
    }

    // Reverse K Nodes in the linked list (Recursive Way)
    node *reverseKNodes(node *&head, int k){
        node *prev = head;
        node *curr = head -> next;
        int count = 0;
        while(curr != NULL && count < k-1){
            prev -> next = curr -> next;
            curr -> next = head;
            head = curr;
            curr = prev-> next;
            count++;
        }
        if(curr != NULL){
            prev->next = reverseKNodes(curr, k);
        }        
        return head;
    }
    

    // Display all the nodes
    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            // iterator
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    node *head = NULL;
    head->insertAtHead(head, 6);
    head->insertAtHead(head, 5);
    head->insertAtHead(head, 4);
    head->insertAtHead(head, 3);
    head->insertAtHead(head, 2);
    head->insertAtHead(head, 1);
    head->display(head);
    // node* newHead = head -> reverseIter(head);
    node *newHead = head->reverseKNodes(head, 3);
    newHead->display(newHead);
    return 0;
}