#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,10,20,20,20,30};
    int res=0;
    for(int i=1; i<6; i++){
        if(arr[i]!=arr[res]){
            arr[res+1]=arr[i]; 
            res++;
        }
    }
    for(int i=0; i<=res;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}