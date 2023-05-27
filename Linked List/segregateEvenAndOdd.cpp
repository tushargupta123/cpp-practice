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

Node *segregate(Node *head){
    Node *es = NULL,*ee = NULL,*os=NULL,*oe = NULL;
    for(Node *curr=head; curr!=NULL; curr=curr->next){
        int x = curr->data;
        if(x%2==0){
            if(es==NULL){
                es = curr;
                ee = es;
            }else{
                ee->next = curr;
                ee = ee->next;
            }
        }else{
            if(os==NULL){
                os = curr;
                oe = os;
            }else{
                oe->next = curr;
                oe = oe->next;
            }
        }
    }
    if(os==NULL|| es==NULL){
        return head;
    }
        ee->next = os;
        oe->next = NULL;
    return es;
}


int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head = segregate(head);
    printList(head);
}