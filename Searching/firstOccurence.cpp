#include<iostream>
using namespace std;

int main(){
    int arr[] = {5,10,10,15,20,20,20};
    int low = 0;
    int high =6;
    int ele=20;
    int mid;
    while(low <= high){
        mid=(low+high)/2;
        if(arr[low] > ele){
            high = mid-1;
        }else if(arr[low] < ele){
            low = mid+1;
        }else{
            if(arr[mid-1] != ele){
                cout<<mid;
                break;
            }else{
            high = mid-1;
            }
        }
    }
}