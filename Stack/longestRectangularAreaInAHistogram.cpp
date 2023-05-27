#include<iostream>
#include<stack>
using namespace std;

int longestArea(int arr[] ,int n){
    stack<int> s;
    int res = 0,tp;
    for(int i=0;i<n;i++){
        while(s.empty() == false && arr[s.top()] >= arr[i]){
            tp = s.top();
            s.pop();
            int curr = arr[tp] * ((s.empty()) ? i : (i-s.top()-1));
            res = max(res, curr);
        }
        s.push(i);
    }
    while(s.empty() == false){
        tp = s.top();
        s.pop();
        int curr = arr[tp] * ((s.empty()) ? n : (n-s.top()-1));
        res = max(res,curr);
    }
    return res;
}

int main(){
    int arr[] = {6,2,5,4,1,5,6};
    cout<<longestArea(arr,7);
}