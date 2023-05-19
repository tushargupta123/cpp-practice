#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int arr[] = {20,10,30,100,5};
    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+5);
    int sum = 0;
    int items = 0;
    while(sum <35){
        cout<<pq.top()<<" ";
        sum += pq.top();
        pq.pop();
        items++;
    }
    cout<<endl<<"Total number of items"<<items;
}