#include<iostream>
using namespace std;

void countSort(int arr[],int n,int exp){
    int count[10];
    int *output = new int[n];
    for(int i = 0; i < 10;i++){
        count[i] =0;
    }
    for(int i = 0; i < n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[((arr[i]/exp)%10)]-1] = arr[i];
        count[((arr[i]/exp)%10)]--;
    }
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[],int n){
    int mx = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>mx){
            mx=arr[i];
        }
    }
    for(int exp=1;(mx/exp)>0;exp=exp*10){
        countSort(arr,n,exp);
    }
}

int main(){
    int arr[] = {20,10,40,35,45,6,100,234};
    int n= sizeof(arr)/sizeof(int);
    radixSort(arr,n);
    for(int x: arr){
        cout<<x<<" ";
    }
    return 0;
}