#include<iostream>
#include<deque>
using namespace std;

int main(){
    int arr[] ={20,40,30,10,60};
    deque<int> dq;
    for(int i =0; i<3; i++){
    while(!dq.empty() && arr[i] >= dq.back()){
        dq.pop_back();
    }
    dq.push_back(arr[i]);
    }
    for(int i = 3; i<5; i++){
        cout<<dq.front()<<" ";
        while(!dq.empty() && dq.front() <= i-3){
            dq.pop_front();
        }
        while(!dq.empty() && arr[i] >= dq.back()){
        dq.pop_back();
    }
    dq.push_back(arr[i]);
    }
    cout<<dq.front();
}