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

    // Making cycle
    void makeCycle(node *&head, int pos)
    {
        node *temp = head;
        node *pos_ptr;
        int count = 1;
        while (temp->next != NULL)
        {
            if (count == pos)
            {
                pos_ptr = temp;
            }
            // Iterator
            temp = temp->next;
            count++;
        }
        temp->next = pos_ptr;
    }

    // Detecting cycle in Linked list (Using Hare and Tortoise algorithm)
    bool detectCycle(node *head)
    {
        node *fast = head;
        node *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            // Move fast two steps forward
            fast = fast->next->next;
            // Move slow one step forward
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }

    // Removing cycle using little modification in same algorithm
    // Assuming that there is cycle
    void removeCycle(node *&head){
        node *fast = head;
        node *slow = head;
        // Since we already assumed that there is cycle
        do{
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);
        fast = head;
        // Corner cases -> When cycle is formed at head.
        if(slow == head){
            while(slow-> next != fast){
                slow = slow->next;
            }
        }
        // Other cases
        else{
            while (fast->next != slow->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }        
        slow->next = NULL;
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
    head->makeCycle(head, 1);
    cout<<head->detectCycle(head)<<endl;
    head->removeCycle(head);
    head->display(head);
    cout << head->detectCycle(head) << endl;
    return 0;
}