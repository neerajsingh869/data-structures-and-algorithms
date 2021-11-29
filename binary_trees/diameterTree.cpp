#include <iostream>
#include<climits>
using namespace std;

// blueprint for object of node datatype
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

// Reursive approach to find the height of the tree
int heightTreeRecur(node *root)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }
    return max(heightTreeRecur(root->right), heightTreeRecur(root->left)) + 1;
}

// Recursive approach to find the diameter of the tree
int diameterTreeRecur(node *root){
    // Base condition (return 0 since there are no nodes)
    if(root == NULL){
        return 0;
    }
    // calculate the height of left subtree
    int lHeight = heightTreeRecur(root->left);
    // calculate the height of right subtree
    int rHeight = heightTreeRecur(root->right);
    // Diameter of current tree
    int currDiameter = (lHeight + 1) + (rHeight + 1) + 1;
    // Diameter of left subtree
    int leftSubtreeDiameter = diameterTreeRecur(root->left);
    // Diameter of right subtree
    int rightSubtreeDiameter = diameterTreeRecur(root->right);
    // return the maximum of currDiameter, leftSubtreeDiameter and rightSubtreeDiameter
    return max(currDiameter, max(leftSubtreeDiameter, rightSubtreeDiameter));
}

// Recursive approach to find the diameter of the tree
int diameterTreeRecur2(node *root, int* height)
{
    // Base condition
    if (root == NULL)
    {   
        // height of no tree is -1
        *height = -1;
        // diameter of no tree is 0
        return 0;
    }
    int lHeight = 0, rHeight = 0;
    // Diameter of left subtree
    int leftSubtreeDiameter = diameterTreeRecur2(root->left, &lHeight);
    // Diameter of right subtree
    int rightSubtreeDiameter = diameterTreeRecur2(root->right, &rHeight);
    // Diameter of current tree 
    int currDiameter = (lHeight + 1) + (rHeight + 1) + 1;
    *height = max(lHeight, rHeight)+1;
    // return the maximum of currDiameter, leftSubtreeDiameter and rightSubtreeDiameter
    return max(currDiameter, max(leftSubtreeDiameter, rightSubtreeDiameter));
}

// main function
int main()
{
    // constructing tree
    /*          1
              /   \
             2     3
            /       \
           4         5
          / \
         6   7
        /
       8
    */
    // storing the adress of node object built in heap
    node *root = new node(1);
    root->right = new node(3);
    root->left = new node(2);
    root->right->right = new node(5);
    root->left->left = new node(4);
    root->left->left->right = new node(7);
    root->left->left->left = new node(6);
    root->left->left->left->left = new node(8);
    cout << diameterTreeRecur(root) << endl;
    int height = 0;
    cout << diameterTreeRecur2(root, &height) << endl;
    cout<<height<<endl;
    return 0;
}
