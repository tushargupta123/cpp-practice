#include<iostream>
using namespace std;

int main(){
    int arr[] = {5,10,40,30,20,50,60};
    int low = 0,n = (sizeof(arr)/sizeof(int)),mid=0,high=n-1;
    while(low<=high){
        mid = (high+low)/2;
        if((mid==0 || arr[mid]>=arr[mid-1] )&&(mid==(n-1) || arr[mid]>=arr[mid+1])){
            cout<<mid;
        }
        if(mid>0 && arr[mid -1]>=arr[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
}