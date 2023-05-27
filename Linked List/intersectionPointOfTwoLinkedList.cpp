#include<iostream>
#include<unordered_set>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x){
        data = x;
        next = NULL;
    }
};

int intersectionPoint(Node *h1,Node *h2){
    Node *curr = h1;
    unordered_set<Node *> s;
    while(curr != NULL){
        s.insert(curr);
        curr = curr->next;
    }
    curr = h2;
    while(curr != NULL){
        if(s.find(curr)!=s.end()){
            break;
        }
        curr = curr->next;
    }
    return curr->data;
}


int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    Node *head2 = new Node(40);
    head2->next = new Node(50);
    head2->next->next = head->next;
    cout<<intersectionPoint(head,head2);
}