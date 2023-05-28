#include<iostream>
using namespace std;


struct deque{
    int *arr;
    int cap,size,front;
    deque(int c){
        cap = c;
        size=front=0;
        arr = new int[cap];
    }
    bool isFull(){  return (size==cap);}
    bool isEmpty(){ return (size==0);}
    int getRear(){
        if(isEmpty())   return -1;
        return (front+size-1)%cap;
    }
    void insertFront(int x){
        if(isFull())    return;
        front = (front-1+cap)%cap;
        arr[front] = x;
        size++;
    }
    void insertRear(int x){
        if(isFull()) return;
        int rear = getRear();
        rear = (rear+1)%cap;
        arr[rear] = x;
        size++;
    }
    void deleteFront(){
        if(isEmpty()) return;
        front = (front +1)%cap;
        size--;
    }
    void deleteRear(){
        if(isEmpty()) return;
        int rear = getRear();
        rear = (rear-1+cap)%cap;
        size--;
    }
}

int main(){

}