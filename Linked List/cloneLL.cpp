#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *random;
    Node (int x){
        data = x;
        next = NULL;
        random = NULL;
    }
};

void printList(Node *head){            
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->data<<" "<<curr->random->data<<endl;
        curr = curr->next;
    }
}

// using hashing             => O(n) time + O(n) space
// Node* clone(Node* head)
// {
//     unordered_map<Node*, Node*> mp;
//     Node *temp, *nhead;
//     temp = head;
//     nhead = new Node(temp->data);
//     mp[temp] = nhead;
//     while (temp->next != NULL) {
//         nhead->next = new Node(temp->next->data);
//         temp = temp->next;
//         nhead = nhead->next;
//         mp[temp] = nhead;
//     }
//     temp = head;
//     while (temp != NULL) {
//         mp[temp]->random = mp[temp->random];
//         temp = temp->next;
//     }
//     return mp[head];
// }

// using same linkedlist        =>O(n) time + O(1) space
Node *clone(Node *head){
    if (head == NULL) {
        return NULL;
    }
     
    // Step 1: Create new nodes and insert them next to the original nodes
    Node* curr = head;
    while (curr != NULL) {
        Node* newNode = new Node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
     
    // Step 2: Set the random pointers of the new nodes
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
     
    // Step 3: Separate the new nodes from the original nodes
    curr = head;
    Node* clonedHead = head->next;
    Node* clonedCurr = clonedHead;
    while (clonedCurr->next != NULL) {
        curr->next = curr->next->next;
        clonedCurr->next = clonedCurr->next->next;
        curr = curr->next;
        clonedCurr = clonedCurr->next;
    }
    curr->next = NULL;
    clonedCurr->next = NULL;
     
    return clonedHead;
}


int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->random = head->next->next;
    head->next->random = head->next->next;
    head->next->next->random = head->next;
    head->next->next->next->random = head;
    head = clone(head);
    printList(head);
}