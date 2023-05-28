#include<iostream>
using namespace std;

// using simple array 

// struct queue{
//     int *arr;
//     int cap;
//     int size;
//     queue(int c){
//         cap = c;
//         size = 0;
//         arr = new int[cap];
//     }
//     bool isEmpty(){
//         if(size == 0)   return true;
//         return false;
//     }
//     bool isFull(){
//         if(size==cap) return true;
//         return false;
//     }
//     void enqueue(int x){
//         if(isFull()) return;
//         arr[size++] = x;
//     }
//     void dequeue(){
//         if(isEmpty())   return;
//         for(int i=0; i<size-1; i++){
//             arr[i] = arr[i+1];
//         }
//         size--;
//     }
//     int getFront(){
//         if(isEmpty())   return -1;
//         return arr[0];
//     }
//     int getRear(){
//         if(isEmpty())   return -1;
//         return arr[size-1];
//     }
// };

// using circular array

struct queue{
    int *arr;
    int cap,size,front;
    queue(int c){
        cap = c;
        size = front = 0;
        arr = new int[cap];
    }
    bool isEmpty(){
        if(size == 0)   return true;
        return false;
    }
    bool isFull(){
        if(size==cap) return true;
        return false;
    }
    void enqueue(int x){
        if(isFull())    return;
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++; 
    }
    void dequeue(){
        if(isEmpty()) return;
        front = (front + 1) % cap;
        size--;
    }
    int getRear(){
        if(isEmpty()) return -1;
        return (front+size-1)%cap;
    }
};

int main(){
    queue q(4);
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    cout<<q.isEmpty()<<endl;
    cout<<q.size<<endl;
}