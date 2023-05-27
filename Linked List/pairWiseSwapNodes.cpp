#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x){
        data = x;
        next = NULL;
    }
};

void printList(Node *head){            
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

Node *pairWiseSwap(Node *head){
    Node *curr = head;
    while(curr != NULL && curr->next != NULL){
        int t = curr->data;
        curr->data = curr->next->data;
        curr->next->data = t;
        curr = curr->next->next;
    }
    return head;
}


int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head = pairWiseSwap(head);
    printList(head);
}