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
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

Node *insertNode(Node *head,int x){             // insertion at beginnning
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

Node *insertEnd(Node *head,int x){          // insertion at end
    Node *temp = new Node(x);
    if(head == NULL) return temp;
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

int main(){
    Node *head = new Node(10);
    // Node *temp1 = new Node(20);
    // Node *temp2 = new Node(30);
    // head->next = temp1;
    // head->next->next = temp2;

    // or

    head->next = new Node(20);
    head->next->next = new Node(30);
    head = insertNode(head,10);
    head = insertNode(head,20);
    head = insertNode(head,30);
    head = insertEnd(head,50);
    head = insertEnd(head,60);
    head = insertEnd(head,70);

    printList(head);
}