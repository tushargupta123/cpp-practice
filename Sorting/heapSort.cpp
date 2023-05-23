#include<iostream>
using namespace std;

void maxHeapify(int arr[],int n,int i){
    int largest = i,left = (2*i)+1,right = (2*i)+2;
    if(left <n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
}

void makeHeap(int arr[],int n){
    for(int i=(n-2)/2; i>=0; i--){
        maxHeapify(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    makeHeap(arr,n);
    for(int i=n-1;i>=1;i--){
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0);
    }
}

int main(){
    int arr[] = {20,10,30,45,5,2};
    heapSort(arr,6);
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;
}