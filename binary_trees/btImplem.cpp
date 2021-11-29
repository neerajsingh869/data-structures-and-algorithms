#include<iostream>
using namespace std;

// blueprint/template for each node of the binary tree
// instead of struct, you can also use class
/* Binary tree node consists of data, a pointer to the
left child and a pointer to the right child */
struct Node{
    int data;
    struct Node* right;
    struct Node* left;
    // Parameterised constructor
    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

int main(){    
    /*    1
         / \
        2   3
    */
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;
    /*    1
         / \
        2   3
           / \
          4   5
    */
    root->right->left = new Node(4);
    root->right->left = new Node(5);
    return 0;
}