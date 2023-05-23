#include<iostream>
using namespace std;

int lumotoPartition(int arr[],int l,int h){
    int i=l-1;
    int pivot = arr[h];
    for(int j=l; j<h;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

int main(){
    int arr[] = {4,2,7,9,10,24,2};
    int k= 3;
    int l=0,r=6;
    while(l<=r){
        int p =lumotoPartition(arr,l,r);
        if(p==k-1){
            cout<<arr[p];
            break;
        }else if(p>k){
            r= p-1;
        }else{
            l=p+1;
        }
    }
}