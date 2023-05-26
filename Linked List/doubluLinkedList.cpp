#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node (int x){
        data = x;
        prev = NULL;
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

Node *insertNode(Node *head,int x){             // insertion at beginnning
    Node *temp = new Node(x);
    temp->next = head;
    if(head!=NULL){
        head->prev = temp;
    }
    return temp;
}

Node *insertEnd(Node *head,int x){
    Node *temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}

Node *reverse(Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    while(curr != NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

Node *deleteFirst(Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}

Node *deleteLast(Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->prev->next = NULL;
    delete curr;
    return head;
}

int main(){
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    head = insertNode(head,40);
    head = insertEnd(head,50);
    head = reverse(head);
    head = deleteFirst(head);
    head = deleteLast(head);
    printList(head);
}