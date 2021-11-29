#include <iostream>
using namespace std;

// blueprint of object of type node in binary trees
class node
{
public:
    int data;
    node *left;
    node *right;
    // parameterised constructor
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// To find the position of target element in inOrder array
int search(int inOrder[], int start, int end, int target){
    for(int i = start; i <= end; i++){
        if(inOrder[i] == target){
            return i;
        }
    }
    /* This condition will never be true because the 
    target variable will always be in inOrder array. */
    // Any element in preOrder will also be in inOrder array.
    return -1;
}

node* buildTree(int preOrder[], int inOrder[], int start, int end){
    static int idx = 0;
    // Base condition
    if(start>end){
        return NULL;
    }
    // current element
    int curr = preOrder[idx];
    // Move to the next element in preOrder array
    idx++;
    // create current root node
    node* currRoot = new node(curr);
    /* if start = end, then the current root node
    is a leaf node. Therefore return current root node */
    if(start == end){
        return currRoot;
    }
    /* Finding the position of current element in 
    inOrder array and storing its position. */
    int pos = search(inOrder, start, end, curr);
    // build left subtree around current root node
    currRoot->left = buildTree(preOrder, inOrder, start, pos-1);
    // build right subtree around current root node
    currRoot->right = buildTree(preOrder, inOrder, pos+1, end);
    
    // return the root node
    return currRoot;
}

/* To verify the results, I am going to print the
inorder sequence of built tree */
void inOrderPrint(node* root){
    // base case
    if(root == NULL){
        return ;
    }   
    // explore left subtree
    inOrderPrint(root->left);
    // print root
    cout<<root->data<<" ";
    // explore right subtree
    inOrderPrint(root->right);
}

void preOrderPrint(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // print root
    cout << root->data << " ";
    // explore left subtree
    preOrderPrint(root->left);    
    // explore right subtree
    preOrderPrint(root->right);
}

int main(){
    int preOrder[] = {1, 2, 4, 3, 5};
    int inOrder[] = {4, 2, 1, 5, 3};
    int n = sizeof(inOrder)/sizeof(inOrder[0]);
    int start = 0;
    int end = n-1;
    node* root = buildTree(preOrder, inOrder, start, end);
    preOrderPrint(root);
    cout<<endl;
    inOrderPrint(root);
    return 0;
}