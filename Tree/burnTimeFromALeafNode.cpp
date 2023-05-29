#include<iostream>
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

int res=0;
int burnTime(Node *root,int leaf,int &dist){
    if(res==0) return 0;
    if(root->key == leaf) {
        dist = 0;
        return 1;
    }
    int ldist = -1;
    int rdist = -1;
    int lh = burnTime(root->left,leaf,ldist);
    int rh = burnTime(root->right,leaf,rdist);
    if(ldist != -1){
        dist = ldist +1;
        res = max(res,dist+rh);
    }else if(rdist!= -1){
        dist = rdist +1;
        res = max(res,dist+lh);
    }
    return max(rh,lh)+1;
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->left->left->left = new Node(50);
    root->left->left->left->left = new Node(60);
    int dist = -1;
    burnTime(root,40,dist);
    cout<<res;
}