#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50,8,9};
    int high = (sizeof(arr)/sizeof(int))-1,low=0,mid=0,ele=10;
    while(low<=high){
        mid = (high+low)/2;
        if(arr[mid]==ele){
            cout<<mid;
        }
        if(arr[low] < arr[mid]){
            if(ele >= arr[low] && ele < arr[mid]){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }else{
            if(ele <= arr[high] && ele > arr[mid]){
                low = mid +1;
            }else{
                high = mid -1;
            }
        }
    }
    return 0;
}