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
// in lumoto element gets to its place and all smaller elements at its left and greater at right

int hoarePartition(int arr[],int l,int h){
    int pivot = arr[l];
    int i = l-1,j=h+1;
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

void quickSort(int arr[],int l,int h){
    if(l<h){
        // int p = lumotoPartition(arr,l,h);
        // quickSort(arr,l,p-1);
        // quickSort(arr,p+1,h);
        int p = hoarePartition(arr,l,h);
        quickSort(arr,l,p);
        quickSort(arr,p+1,h);
    }
}

int main(){
    int arr[] = {50,30,20,10,5,11};
    quickSort(arr,0,5);
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;
}