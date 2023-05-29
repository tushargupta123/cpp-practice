#include<iostream>
#include<math.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node *right;
    Node(int x){
        key = x;
        left = right = NULL;
    }
};

int nodeCount(Node *root){
    if(root == NULL){
        return 0;
    }
    int lh =0,rh=0;
    Node *curr = root;
    while(curr != NULL){
        lh++;
        curr = curr->left;
    }
    while(curr != NULL){
        rh++;
        curr = curr->right;
    }
    if(lh==rh){                     // we check for perfect binary tree if it is perfect binary tree then node count would be 2^n-1 and we can skip whole tree.
                                    // we check if left and right height for that node is equal then it is perfect binary tree
        return pow(2,lh)-1;
    }
    return 1+nodeCount(root->left)+nodeCount(root->right);
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(40);
    root->left->left = new Node(50);
    root->right->right = new Node(60);
    root->right->left = new Node(70);
    cout<<nodeCount(root);
}