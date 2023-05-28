#include <iostream>
#include<queue>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->key << " ";
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return ((max(height(root->left), height(root->right))) + 1);
    }
}

void kthNode(Node *root,int k){
    if(root == NULL)    return;
    if(k == 0){
        cout<<root->key<<" ";
    }else{
        kthNode(root->left,k-1);
        kthNode(root->right,k-1);
    }
}

void breadthTraversal(Node *root){
    if(root == NULL)    return;
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false){
        Node *curr = q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left !=NULL){
            q.push(curr->left);
        }
        if(curr->right !=NULL){
            q.push(curr->right);
        }
    }
}

void breadthTraversalLineByLine(Node *root){
    if(root == NULL)    return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size() >1){
        Node *curr = q.front();
        q.pop();
        if(curr == NULL){       // whenever we see NULL we print a new line and also push another NULL bcs children of previous node has been already pushed to queue.
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<curr->key<<" ";
        if(curr->left !=NULL){
            q.push(curr->left);
        }
        if(curr->right !=NULL){
            q.push(curr->right);
        }
    }
}

int size(Node *root){
    if(root == NULL)    return 0;
    return 1+size(root->left)+size(root->right);
}

int getMax(Node *root){
    if(root == NULL)    return -1;
    return max(root->key,max(getMax(root->left),getMax(root->right)));
}

void leftView(Node *root){
    if(root == NULL)    return;
    cout<<root->key<<" ";
    if(root->left !=NULL)
    leftView(root->left);
    else
    leftView(root->right);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->right = new Node(30);
    root->left->left = new Node(40);
    inorderTraversal(root);
    cout << endl<< height(root)<<endl;
    kthNode(root,1);
    cout<<endl;
    breadthTraversal(root);
    cout<<endl;
    breadthTraversalLineByLine(root);
    cout<<endl<<size(root);
    cout<<endl<<getMax(root)<<endl;
    leftView(root);
}