#include<iostream>
using namespace std;

int main(){
    int arr[] = {2,3,10,6,4,8,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int curr = n-1;
    int res =0;
    for(int i= n-2 ; i>=0 ; i--){
        if(arr[i] > arr[curr])   curr = i;
    }
    for(int i=0; i< curr; i++){
        res = max(res, arr[curr] - arr[i]);
    }
    cout<<res<<endl;
}