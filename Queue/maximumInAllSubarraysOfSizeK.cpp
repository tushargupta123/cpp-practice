#include<iostream>
#include<deque>
using namespace std;

int main(){
    int arr[] = {15,10,12,20,15,32,17};
    int k = 3;
    deque<int> dq;
    dq.push_front(arr[0]);
    for(int i = 0; i <7;i++){
        if(dq.front() < arr[i]){
            dq.push_front(arr[i]);
        }else{
            dq.push_back(arr[i]);
        }
        if(i>1){
            cout<<dq.front()<<" ";
            dq.pop_back();
        }
    }
}