#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int x){
        data = x;
        prev = NULL;
        next = NULL;
    }
}

Node *insertFirst(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->prev = temp;
        temp->next = temp;
        return temp;
    }
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return temp;
}

Node *insertLast(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL){
        temp->prev = temp;
        temp->next = temp;
        return temp;
    }
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return head;
}

int main(){

}