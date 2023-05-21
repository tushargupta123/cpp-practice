#include<iostream>
using namespace std;

int subsetSum(int arr[],int sum,int n){
    if(n==0){
        if(sum==0) return 1;
        else return 0;
    }
    return subsetSum(arr,sum-arr[n-1],n-1)+subsetSum(arr,sum,n-1);
}

int main(){
    int arr[] = {10,5,2,3,6};
    cout<<subsetSum(arr,8,5);
    return 0;
}