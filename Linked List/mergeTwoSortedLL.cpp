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

Node *merge(Node *head1, Node *head2){
    if(head1 == NULL){
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *curr1 = head1;
    Node *curr2 = head2;
    Node *tail = NULL;
    Node *head = NULL;
    if(curr1->data <= curr2->data){
        head = head1;
        tail = head1;
        curr1 = curr1->next;
    }else{
        head = head2;
        tail = head1;
        curr2 = curr2->next;
    }
    while(curr1 != NULL && curr2 != NULL){
        if(curr1->data <= curr2->data){
            tail->next = curr1;
            tail = curr1;
            curr1 = curr1->next;
        }else{
            tail->next = curr2;
            tail = curr2;
            curr2 = curr2->next;
        }
    }
    if(curr1 == NULL){
        tail->next = curr1;
    }else{
        tail->next = curr1;
    }
    return head;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    Node *head2 = new Node(5);
    head2->next = new Node(15);
    merge(head,head2);
    printList(head);
}