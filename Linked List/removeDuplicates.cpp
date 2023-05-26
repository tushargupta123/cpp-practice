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

void deleteDuplicates(Node *head){
    Node *curr = head;
    while(curr->next!=NULL && curr != NULL){
    if(curr->next->data == curr->data){
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }else{
        curr = curr->next;
    }
    }
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    deleteDuplicates(head);
    printList(head);
}