#include <iostream>
#include <queue>
using namespace std;

// blueprint of object of data type node
class node
{
public:
    int data;
    node *right;
    node *left;
    // parameterised constructor
    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

// Function to count the total number of nodes
int countNodesIterWithNull(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<node *> que;
    que.push(root);
    que.push(NULL);
    int total = 0;
    while (!que.empty())
    {
        node *curr = que.front();
        que.pop();
        if (curr != NULL)
        {
            if (curr->left != NULL)
            {
                que.push(curr->left);
            }
            if (curr->right != NULL)
            {
                que.push(curr->right);
            }
            total++;
        }
        else if (!que.empty())
        {
            que.push(NULL);
        }
    }
    return total;
}
// Better iterative approach
int countNodesIterWithoutNull(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<node *> que;
    que.push(root);
    int total = 0;
    while (!que.empty())
    {
        node *curr = que.front();
        que.pop();
        if (curr->left != NULL)
        {
            que.push(curr->left);
        }
        if (curr->right != NULL)
        {
            que.push(curr->right);
        }
        total++;
    }
    return total;
}
int totalRecur1 = 0;
// Recursive algorithm to count the number of nodes
void countNodesRecur1(node* root){
    // base case
    if(root == NULL){
        return;
    }
    /* Implenting the logic of any type of tree traversal i.e
    increase the total as many times as currRoot was printed */
    totalRecur1++;
    // travel to left subtree
    countNodesRecur1(root->left);
    // travel to right subtree
    countNodesRecur1(root->right);
}

// Better Recursive algorithm to count the number of nodes
int countNodesRecur2(node *root)
{
    // base case
    if (root == NULL)
    {   
        return 0;
    }
    // left tree count + right tree count + 1
    return countNodesRecur2(root->left) +
     countNodesRecur2(root->right) + 1;
}

int main()
{
    // constructing a binary tree
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(50);
    root->left->left = new node(50);
    root->left->right = new node(23);
    root->right->left = new node(10);
    root->right->right = new node(15);
    cout << countNodesIterWithNull(root) << endl;
    cout << countNodesIterWithoutNull(root) << endl;
    countNodesRecur1(root);
    cout<< totalRecur1 << endl;
    cout<<countNodesRecur2(root) << endl;
    return 0;
}