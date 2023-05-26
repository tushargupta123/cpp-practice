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

Node *sortedInsert(Node *head,int x){             // insertion at beginnning
    Node *temp = new Node(x);
    Node *curr = head;
    if(head == NULL){
        return temp;
    }
    if(x<head->data){
        temp->next = head;
        return temp;
    }
    while(curr->next!=NULL){
        if(curr->data < x && curr->next->data >= x){
            temp->next = curr->next;
            curr->next = temp;
        }
        curr = curr->next;
    }
    return head;
}


int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head = sortedInsert(head,25);
    printList(head);
}