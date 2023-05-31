#include<iostream>
#include<map>
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

// here we just traverse inorder and while traverse through left we decrease the horizontal distance by 1 and while traverse through right we increase 
// the horizontal distance by 1 and we store it in map key being horizontal distance of that node.

void vSumR(Node *root,int hd,map<int,int> &mp){
    if(root == NULL)    return;
    vSumR(root->left,hd-1,mp);
    mp[hd] += root->key;
    vSumR(root->right,hd+1,mp);
}

void vSum(Node *root){
    map<int,int> mp;
    vSumR(root,0,mp);
    for(auto x:mp){
        cout<<x.second<<" ";
    }
}

int main(){
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(30);
    root->left->right = new Node(10);
    root->left->left = new Node(3);
    root->right->right = new Node(35);
    vSum(root);
}