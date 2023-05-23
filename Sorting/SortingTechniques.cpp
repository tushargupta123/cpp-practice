#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int swapped = false;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min_index =i;
        for(int j=i+1;j<n-1;j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
    }
    swap(arr[min_index],arr[i]);
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int* mergeSort(int a[],int b[],int n,int m){
    int *arr = new int[n+m];
    int i=0,j=0;
    while(i<n || j<m){
    if(a[i]<=b[j]){
        arr[i+j] = a[i];
        i++;
    }else{
        arr[j+i] = b[j];
        j++;
    }
    }
    while(j<m){
        arr[i+j] = b[j];
        j++;
    }
    while(i<n){
        arr[i+j] = a[i];
        i++;
    }
    return arr;
}

int main(){
    int arr[] = {2,12,8,5,20};
    int n = sizeof(arr)/sizeof(int);
    // bubbleSort(arr,n);
    // selectionSort(arr,n);
    insertionSort(arr,n);
    // for(int x:arr){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    int arr2[] = {15,10,25};
    int m = sizeof(arr2)/sizeof(int);
    insertionSort(arr2,m);
    int *arr3 = mergeSort(arr,arr2,n,m);
    for(int i=0;i<n+m;i++){
        cout<<arr3[i]<<" ";
    }
    return 0;
}