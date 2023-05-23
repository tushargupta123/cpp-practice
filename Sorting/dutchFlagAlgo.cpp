// all the pivots (1's) should be together and 0's at left side and 2's at right side
#include<iostream>
using namespace std;

int main(){
    int arr[]= {1,0,2,0,1,0,2,0,2,1};
    int n = sizeof(arr)/sizeof(int);
    int low = 0,mid= 0,high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int x:arr){
        cout<<x<<" ";
    }
}