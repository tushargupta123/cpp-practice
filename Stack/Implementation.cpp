#include<iostream>
#include<vector>
using namespace std;

// array implementation

// struct stack{
//     int *arr;
//     int cap;
//     int top;
//     stack(int c){
//         cap = c;
//         arr = new int[cap];
//         top = -1;
//     }
//     void push(int x){
//         if(top == cap-1){
//             cout<<"OVERFLOW"<<endl;
//             return;
//         }
//         top++;
//         arr[top] = x;
//     }
//     int pop(){
//         if(top==-1){
//             cout<<"UNDERFLOW"<<endl;
//             return -1;
//         }
//         int res = arr[top];
//         top--;
//         return res;
//     }
//     int peek(){
//         if(top==-1){
//             cout<<"UNDERFLOW"<<endl;
//             return -1;
//         }
//         return arr[top];
//     }
//     int size(){
//         return top+1;
//     }
//     bool isEmpty(){
//         return (top == -1);
//     }
// };

// vector implementation

// struct stack{
//     vector<int> v;
//     void push(int x){
//         v.push_back(x);
//     }
//     int pop(){
//         if(v.size() == 0){
//             cout<<"UNDERFLOW"<<endl;
//             return -1;
//         }
//        int res = v.back();
//        v.pop_back();
//        return res;
//     }
//     int peek(){
//         if(v.size() == 0){
//             cout<<"UNDERFLOW"<<endl;
//             return -1;
//         }
//         return v.back();
//     }
//     int size(){
//         return v.size();
//     }
//     bool isEmpty(){
//         return v.empty();
//     }
// };

// Linked List implementation

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

struct stack{
    Node *head;
    int sz;
    stack(){
        head = NULL;
        sz=0;
    }
    void push(int x){
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }
    int pop(){
        if(head == NULL){
            return -1;
        }
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        sz--;
        return res;
    }
    int size(){
        return sz;
    }
    int isEmpty(){
        return (sz==0);
    }
    int peek(){
        if(head == NULL){
            return -1;
        }
        return head->data;
    }
};

// Two stack Implementation in an array
struct TwoStack{        // we will be working bidirectionally
    int *arr,cap,top1,top2;
    TwoStack(int n){cap=n;top1=-1;top2=cap;arr=new int[cap];};
    void push1(int x){
        if(top1<top2-1){
            top1++;
            arr[top1] = x;
        }
    }
    void push2(int x){
        if(top1<top2-1){
            top2--;
            arr[top2] = x;
        }
    }
    int pop1(){
        if(top1>=0){
            int res = arr[top1];
            top1--;
            return res;
        }else{
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
    }
    int pop2(){
        if(top2<cap){
            int res = arr[top2];
            top2++;
            return res;
        }else{
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
    }
};

// Undo and redo operations are done using stack data structure only

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
}