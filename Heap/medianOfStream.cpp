#include<iostream>
#include<queue>
using namespace std;

// here we use two heap min and max heap. we store first element in min heap then we have to maintain size of both heap equal if any new element come it goes 
// to min heap and side by side we make sure that all elements less are less than top of max heap .
// then in case of odd elements we print top of min heap and in case of even elements we print sum of top both heap / 2.

void medianOfStream(int arr[],int n){
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int> > g;
    s.push(arr[0]);
    cout<<s.top()<<" ";
    for(int i=1;i<n;i++){
        if(s.size()>g.size()){
            if(s.top()>arr[i]){
                g.push(s.top());
                s.pop();
                s.push(arr[i]);
            }else{
                g.push(arr[i]);
            }
            cout<<((s.top()+g.top())/2.0)<<" ";
        }else{
            if(s.top()>=arr[i]){
                s.push(arr[i]);
            }else{
                g.push(arr[i]);
                s.push(g.top());
                g.pop();
            }
            cout<<s.top()<<" ";
        }
    }
}

int main(){
    int arr[] = {12,15,10,5,8,7,16};
    medianOfStream(arr,7);
}