#include<iostream>
#include<vector>
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

// serialize is converting tree into array or string . here we do preorder traversal and in place of NULL we put -1 in arr

const int EMPTY = -1;
void serialize(Node *root,vector<int> &arr){
    if(root == NULL){
        arr.push_back(EMPTY);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left,arr);
    serialize(root->right,arr);
}

int index = 0;
Node *deserialize(vector<int> &arr){
    if(index == arr.size()) return NULL;
    int val = arr[index++];
    if(val==EMPTY) return NULL;
    Node *root = new Node(val);
    root->left = deserialize(arr);
    root->right = deserialize(arr);
    return root;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->left->left->left = new Node(50);
    root->left->left->left->left = new Node(60);
    vector<int> arr;
    serialize(root, arr);
    for(int x:arr){
        cout<<x<<" ";
    }
}