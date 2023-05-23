#include<iostream>
using namespace std;

int hoarePartition(int arr[],int l,int n){
    int pivot = arr[l];
    int i = l-1,j=n;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j){
            return j;
        }
        swap(arr[i],arr[j]);
    }
}

int main(){
    int arr[] = {5,3,8,4,2,7,1,4};
    cout<<hoarePartition(arr,0,8);
    return 0;
}