#include<iostream>
using namespace std;

void lumotoPartition(int arr[],int n,int p,int l){
    swap(arr[n-1],arr[p]);
    int i=l-1;
    int pivot = arr[n-1];
    for(int j=0; j<n-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[n-1]);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]= {50,30,20,10,5,11};
    lumotoPartition(arr,6,2,0);
    return 0;
}