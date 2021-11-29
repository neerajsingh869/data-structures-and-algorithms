#include<iostream>
#include<queue>
using namespace std;

// blueprint of object of type node in binary trees
class node{
public:
    int data;
    node* left;
    node* right;
    // parameterised constructor
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// preorder traversal
void preorderTraversal(node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }
    // root
    cout << root->data << " ";
    // explore left subtree
    preorderTraversal(root->left);
    // explore right subtree
    preorderTraversal(root->right);
}

// inorder traversal
void inorderTraversal(node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }
    // explore left subtree
    inorderTraversal(root->left);
    // root
    cout << root->data << " ";
    // explore right subtree
    inorderTraversal(root->right);
}

// postorder traversal
void postorderTraversal(node *root)
{
    // base condition
    if (root == NULL)
    {
        return;
    }
    // explore left subtree
    postorderTraversal(root->left);
    // explore right subtree
    postorderTraversal(root->right);
    // root
    cout << root->data << " ";
}

// level order traversal
void levelOrderTraversal1(node* root){
    // base case
    if(root == NULL){
        return ;
    }
    queue<node*> que;
    que.push(root);
    que.push(NULL);
    while(!que.empty()){
        // node to be explored
        node* curr = que.front();
        // remove it from the queue
        que.pop();
        // You can also write the code without using NULL
        /* if the node to be explored is not null, then print it out and then 
        push its left node pointer or right node pointer or both in the queue */
        if(curr != NULL){
            cout<<curr->data<<" ";
            if (curr->left != NULL)
            {
                que.push(curr->left);
            }
            if (curr->right != NULL)
            {
                que.push(curr->right);
            }
        }
        /* if the node to be explored is NULL, then check whether the queue
        is empty or not. If not, then push back NULL in the queue */
        else if(!que.empty()){
            que.push(NULL);
        }
        // if(curr==NULL && !que.empty()){
        //     que.push(NULL);
        // }
    }

}

// level order traversal (Without NULL)
void levelOrderTraversal2(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    queue<node *> que;
    que.push(root);
    while (!que.empty())
    {
        // node to be explored
        node *curr = que.front();
        // remove it from the queue
        que.pop();
        // Print the node data
        cout << curr->data << " ";
        if (curr->left != NULL)
        {
            que.push(curr->left);
        }
        if (curr->right != NULL)
        {
            que.push(curr->right);
        }
    }
}

int main(){
    /*     1
         /   \
        2     3
       / \   / \
      4   5 6   7
    */
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preorderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    cout<<endl;
    levelOrderTraversal1(root);
    cout<<endl;
    levelOrderTraversal2(root);
    return 0;
}