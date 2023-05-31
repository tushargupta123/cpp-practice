#include<iostream>
#include<queue>
using namespace std;

void sortedKArray(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<=k;i++){
        q.push(arr[i]);
    }
    int index = 0;
    for(int i=k+1;i<n;i++){
        arr[index++] = q.top();
        q.pop();
        q.push(arr[i]);
    }
    while(!q.empty()){
        arr[index++] = q.top();
        q.pop();
    }
}

int main(){
    int arr[] = {9,8,7,19,18};
    sortedKArray(arr,5,2);
    for(int x:arr){
        cout<<x<<" ";
    }
}