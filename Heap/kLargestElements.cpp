#include<iostream>
#include<queue>
using namespace std;

// we make min heap of required k elements then we compare top with current element if current element is greater than it is replaced and hence at last we get k largest element

void kLargestElement(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> q;         // we use this syntax whenever we want that pq should store in increasing order else it stores in decreasing order
    for(int i=0;i<k;i++){
        q.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        int top = q.top();
        if(top < arr[i]){
            q.pop();
            q.push(arr[i]);
        }
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
}

int main(){
    int arr[] = {20,30,10,25,45};
    kLargestElement(arr,5,3);
}