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


int findFromEnd(Node *head,int k){
    if(head == NULL){
        return -1;
    }
    Node *start = head;
    Node *front = head;
    int curr=0;
    while(curr<k){
        if(front == NULL) return -1;
        front = front->next;
        curr++;
    }
    while(front!=NULL){
        front = front->next;
        start = start->next;
    }
    return start->data;
}


int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    int k=2;
    cout<<findFromEnd(head,k);
}