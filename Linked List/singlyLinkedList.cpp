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

Node *insertAtAPos(Node *head,int pos,int x){
    Node *temp = new Node(x);
    if(pos == 1){
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for(int i=0;(i<pos-2)&&(curr!=NULL);i++){
        curr = curr->next;
    }
    if(curr == NULL){
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node *deleteFirst(Node *head){
    if(head == NULL){
        return NULL;
    }
    Node *temp = head->next;
    delete head;
    return temp;
}

Node *deleteLast(Node *head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    delete (curr->next);
    curr->next = NULL;
    return head;
}

int searchNode(Node *head,int x){
    int pos = 1;
    Node *curr = head;
    while(curr != NULL){
        if(curr->data == x){
            return pos;
        }else{
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}

Node *reverse(Node *head){
    Node *prev = NULL;
    Node *next = head->next;
    Node *curr = head;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    head = deleteFirst(head);
    head = deleteLast(head);
    head = insertAtAPos(head,2,55);
    head = reverse(head);
    printList(head);
    // cout<<endl<<searchNode(head,30);
}