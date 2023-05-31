#include<iostream>
#include<queue>
using namespace std;

// we use max heap and store diff be value and current element if it is less than top of heap then we replace it.

void kClosestElement(int arr[],int n,int k,int val){
    priority_queue<pair<int,int>> q;
    for(int i=0;i<k;i++){
        q.push({abs(arr[i]-val),i});
    }
    for(int i=k;i<n;i++){
        if(abs(arr[i]-val)< q.top().first){
            q.pop();
            q.push({abs(arr[i]-val),i});
        }
    }
    while(!q.empty()){
        cout<<arr[q.top().second]<<" ";
        q.pop();
    }
}

int main(){
    int arr[] = {10,20,30,40,50};
    kClosestElement(arr,5,3,25);
}