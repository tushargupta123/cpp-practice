#include<iostream>
#include<unordered_set>
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

// we find that if sum-current_value exists in the set or not while doing preorder traversal.

bool isSumPair(Node *root,int sum,unordered_set<int> &s){
    if(root == NULL) return false;
    if(isSumPair(root->left,sum,s)){
        return true;
    }
    if(s.find(sum-root->key) != s.end()){
        return true;
    }else{
        s.insert(root->key);
    }
    return isSumPair(root->right,sum,s);
}

int main(){
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(30);
    root->left->right = new Node(10);
    root->left->left = new Node(3);
    root->right->right = new Node(35);
    unordered_set<int> s;
    cout<<isSumPair(root,43,s);
}