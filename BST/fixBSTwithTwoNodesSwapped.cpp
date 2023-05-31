#include<iostream>
#include<limits.h>
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

// we use idea of inorder traversal . if any value is less than the previous value then we will makr it as inappropriate node and find another node and then replace that

Node *prev = NULL;
Node *first = NULL, *second = NULL;
void fixBST(Node *root){
    if(root=NULL)   return;
    fixBST(root->left);
    if(prev != NULL && root->key < prev->key){
        if(first == NULL){
            first = prev;
        }
        second = root;
    }
    prev = root;
    fixBST(root->right);
    swap(first->key, second->key);
}

bool checkBST(Node *root,int min = INT_MIN,int max = INT_MAX){
    if(root==NULL)  return true;
    return ((root->key > min) && (root->key < max) && (checkBST(root->left,min,root->key)) && checkBST(root->right,root->key,max));
}


int main(){
    Node *root = new Node(20);
    root->left = new Node(35);
    root->right = new Node(30);
    root->left->right = new Node(10);
    root->left->left = new Node(3);
    root->right->right = new Node(8);
    cout<<checkBST(root)<<endl;
    fixBST(root);
    cout<<checkBST(root)<<endl;
}