#include<iostream>
using namespace std;

bool isFeasible(int arr[],int n,int k, int ans){
    int sum=0,req=1;
    for(int i=0; i<n; i++){
        if(sum+arr[i] > ans){
            req++;
            sum = arr[i];
        }else{
            sum+=arr[i];
        }
    }
    return (req<=k);
}

int minPages(int arr[],int n,int k){
    int sum = 0,mx=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        mx = max(mx,arr[i]);
    }
    int low = mx,high = sum,res=0;
    while(low<=high){
        int mid = (high+low)/2;
        if(isFeasible(arr,n,k,mid)){
            res = mid;
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return res;
}

int main(){
    int arr[] = {10,5,20};
    int n = 3,k=2;
    cout<<minPages(arr,n,k);
    return 0;
}