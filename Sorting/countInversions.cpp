#include<iostream>
using namespace std;

int countAndMerge(int arr[],int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int *left = new int[n1];
    int *right = new int[n2];
    for(int i=0; i<n1; i++){
        left[i] = arr[l+i];
    }
    for(int i=0; i<n2; i++){
        right[i] = arr[m+i+1];
    }
    int res= 0,i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
            res = res + (n1-i);
        }
        k++;
    }

        while(i<n1){
            arr[k] = left[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = right[j];
            j++;
            k++;
        }
    return res;
}

int countInversion(int arr[],int l,int r){
    int res = 0;
    if(l<r){
    int mid = l + ((r-l)/2);
    res += countInversion(arr,l,mid);
    res += countInversion(arr,mid+1,r);
    res += countAndMerge(arr,l,mid,r);
    }
    return res;
}

int main(){
    int arr[] = {2,4,1,3,5};
    cout<<countInversion(arr,0,5);
    return 0;
}