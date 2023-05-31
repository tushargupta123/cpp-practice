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


// 1st way
// here we simply give upper and lower bound to every node for root node it is -infinity to +infinity
// as we go in left we change upper bound to parent node value
// as we go in right we change lower bound to parent node value
// and we check whether that nodes value lie in given range or not.

bool checkBST(Node *root,int min = INT_MIN,int max = INT_MAX){
    if(root==NULL)  return true;
    return ((root->key > min) && (root->key < max) && (checkBST(root->left,min,root->key)) && checkBST(root->right,root->key,max));
}


// 2nd way
// we will use the fact that inorder traversal of bst is sorted array

int prev = INT_MIN;
bool isBST(Node *root){
    if(root==NULL)  return true;
    if(!isBST(root->left))  return false;
    if(root->key <= prev)   return false;
    prev = root->key;
    return isBST(root->right);
}


int main(){
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(30);
    root->left->right = new Node(10);
    root->left->left = new Node(3);
    root->right->right = new Node(35);
    cout<<checkBST(root);
}