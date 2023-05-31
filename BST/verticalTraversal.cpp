#include<iostream>
#include<map>
#include<vector>
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

void vtR(Node *root,int hd,auto &mp){
    if(root == NULL)    return;
    vtR(root->left,hd-1,mp);
    mp[hd].push_back(root->key);
    vtR(root->right,hd+1,mp);
}

void verticalTarversal(Node *root){
    if(root==NULL)  return;
    map<int,vector<int>> mp;
    vtR(root,0,mp);
    for(auto x:mp){
        for(auto y:x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(50);
    root->left->left = new Node(40);
    verticalTarversal(root);
}