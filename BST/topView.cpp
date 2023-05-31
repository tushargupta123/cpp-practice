#include<iostream>
#include<map>
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

// here we just breadth-wise traversal and while traverse through left we decrease the horizontal distance by 1 and while traverse through right we increase 
// the horizontal distance by 1 and we store it in map key being horizontal distance of that node.
// we print every element on top corresponding to each horizontal distance

void topView(Node *root){
    if(root==NULL) return;
    map<int,int> mp;
    queue<pair<Node *,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        mp.insert({hd,curr->key});
        q.pop();
        if(curr->left != NULL){
            q.push({curr->left,hd-1});
        }
        if(curr->right != NULL){
            q.push({curr->right,hd+1});
        }
    }
    for(auto x:mp){
        cout<<x.second<<" ";
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(40);
    root->left->right->right = new Node(50);
    topView(root);
}