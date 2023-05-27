#include<iostream>
using namespace std;

struct stack{
    int *arr;
    int cap;
    int top;
    stack(int c){
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    void push(int x){
        if(top == cap-1){
            cout<<"OVERFLOW"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    int pop(){
        if(top==-1){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        int res = arr[top];
        top--;
        return res;
    }
    int peek(){
        if(top==-1){
            cout<<"UNDERFLOW"<<endl;
            return -1;
        }
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return (top == -1);
    }
};

void printSpan(int arr[],int n){
    stack s(n);
    s.push(0);      // we store index
    cout<<1<<" ";
    for(int i=1;i<n;i++){
        while(s.isEmpty() == false && arr[s.peek()] <= arr[i]){
            s.pop();        // we pop whenever next element is greater than current top 
        }
        int span = s.isEmpty() ? i+1: i- s.peek();
        cout<<span<<" ";
        s.push(i); 
    }
}

// {60,10,15,20,35,50}
//   1  1  2  3  4  5
// we print number of elements which are less than or equal to that current element on left side

int main(){
    int arr[] = {60,10,15,20,35,50};
    printSpan(arr,6);
}