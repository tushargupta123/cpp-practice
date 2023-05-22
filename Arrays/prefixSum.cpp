#include<iostream>
using namespace std;

int* prefix_sum(int arr[],int n){
    int *prefix = new int[n];
    prefix[0] = arr[0];
    for(int i = 1; i < n;i++){
        prefix[i] = arr[i] + prefix[i-1];
    }
    return prefix;
}

int getSum(int arr[],int start, int end){
    if(start == 0){
        return arr[end];
    }else{
        return (arr[end]-arr[start]);
    }
}

int main(){
    int arr[] = {2,8,3,9,6,5,4};
    int n = sizeof(arr)/sizeof(int);
    int *prefix = prefix_sum(arr,n);
    cout<<getSum(prefix,0,2)<<endl;
}