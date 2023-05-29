#include<iostream>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int x){
        key = x;
        left = right = NULL;
    }
};

int preIndex = 0;
Node *convert(int in[],int pre[],int is,int ie){
    if(is>ie)   return NULL;
    Node *root = new Node(pre[preIndex++]);
    int inIndex;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->key){
            inIndex = i;
        }
    }
    root->left = convert(in,pre,is,inIndex-1);
    root->right = convert(in,pre,inIndex+1,ie);
    return root;
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

int main(){
    int in[] = {20,10,40,30,50};
    int pre[] = {10,20,30,40,50};
    Node *root = convert(in,pre,0,4);
    inorderTraversal(root);
}