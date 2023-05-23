#include<iostream>
using namespace std;

int main(){
    int arr1[] = {3,5,10,10,10,15,20};
    int arr2[] = {3,7,10,15};
    int n = sizeof(arr1)/sizeof(int);
    int m = sizeof(arr2)/sizeof(int);
    int i=0,j=0;
    while(i<n && j <m){
        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            j++;
            i++;
        }else if(arr1[i]>arr2[j]){
            j++;
        }else{
            i++;
        }
    }
}