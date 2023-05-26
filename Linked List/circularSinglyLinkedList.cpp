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

void printList(Node *head){              // whatever modifications we made in head pointer here it will not be copied in out linkedlist bcs head is a copy of original head pointer
    Node *curr = head;
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr != head);
}

Node *insertFirst(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }else{
        temp->next=head->next;
        head->next=temp;
        int t = head->data;
        head->data=temp->data;
        temp->data=t;
    return head;
    }
}

Node *insertLast(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }else{
        temp->next=head->next;
        head->next=temp;
        int t = head->data;
        head->data=temp->data;
        temp->data=t;
    return temp;
    }
}

Node *deleteFirst(Node *head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    head->data = head->next->data;
    Node *temp = head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}

Node *deleteMiddle(Node *head,int k){
    if(head == NULL){
        return NULL;
    }
    if(k==1){
        return deleteFirst(head);
    }else{
        Node *curr = head;
        for(int i=0; i<k-2;i++){
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next= curr->next->next;
        delete temp;
        return head;
    }
}


int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = head;
    head = insertFirst(head,40);
    head = insertLast(head,50);
    head = deleteFirst(head);

    printList(head);
}