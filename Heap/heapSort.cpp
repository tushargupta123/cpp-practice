#include<iostream>
using namespace std;

void maxHeap(int arr[],int n,int i){
    int lt = 2*i+1, rt = 2*i+2;
    int largest = i;
    if(lt<n && arr[lt]>arr[i]){
        largest = lt;
    }
    if(rt < n && arr[rt]>arr[largest]){
        largest = rt;
    }
    if(largest !=i){
    swap(arr[i],arr[largest]);
    maxHeap(arr,n,largest);
    }
}

void buildHeap(int arr[],int size){
    for(int i=(size-2)/2 ; i>=0; i--){
        maxHeap(arr,size,i);
    }
}

void heapSort(int arr[],int size){
    buildHeap(arr,size);
    for(int i=size-1; i>=0; i--){
    swap(arr[0],arr[i]);
    maxHeap(arr,i,0);
    }
}

int main(){
    int arr[] = {20,10,45,23,67};
    heapSort(arr,5);
    for(int x:arr){
        cout<<x<<" ";
    }
}