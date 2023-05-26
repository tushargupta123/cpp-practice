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

void deletePtr(Node *ptr){
    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete (temp);
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    printList(head);
}