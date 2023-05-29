#include<iostream>
using namespace std;

struct TreeNode{
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int k){
        key = k;
        left = right = NULL;
    }
};

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

Node *convert(TreeNode *root,Node *head){
    if(root == NULL) return head;
    head = convert(root->left,head);
    Node *temp = new Node(root->key);
    if(head==NULL){
        head = temp;
        return head;
    }else{
        Node *curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
    head = convert(root->right,head);
    return head;
}

void printList(Node *head){
    if(head==NULL) return;
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(35);
    Node *head = NULL;
    head = convert(root,head);
    printList(head);
}