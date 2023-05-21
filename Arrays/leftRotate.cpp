#include<iostream>
using namespace std;

void reverse(int arr[],int start,int end){
    while(start < end){
        swap(arr[start] , arr[end]);
        start++;
        end--;
    }
}

void leftRotate(int arr[],int n,int d){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int d = 2;
    leftRotate(arr,5,d);
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;
}