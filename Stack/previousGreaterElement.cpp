#include<iostream>
#include<stack>
using namespace std;

void previousGreatest(int arr[],int n){
    stack<int> s;
    s.push(arr[0]);
    for(int i=0;i<n;i++){
        while(s.empty() == false && arr[i] >= s.top()){
            s.pop();
        }
        if(s.empty()){
            cout<<-1<<" ";
        }else{
            cout<<s.top()<<" ";
        }
        s.push(arr[i]);
    }
}

// previous greatest element means that we have to check previous element if it is greater than current element then return it else check for greater element
// in left side of array and when we found one we return it else if it is greatest then return -1

//  if we have to find next greatest element than we have to traverse it from right to left

int main(){
    int arr[] = {15,10,18,12,4,6,2,8};
    previousGreatest(arr,8);
}