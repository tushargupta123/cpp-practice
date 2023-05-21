// a leader is an element in array whose all right hand side elements are smaller than that element
#include<iostream>
using namespace std;

int main(){
    int arr[] = {7,10,4,10,6,5,2};
    int n = sizeof(arr)/sizeof(int);
    int curr_leader = arr[n-1];
    cout<<curr_leader<<endl;
    for(int i=n-2; i>=0; i--){
        if(arr[i]>curr_leader){
            curr_leader = arr[i];
            cout<<curr_leader<<endl;
        }
    }
    return 0;
}