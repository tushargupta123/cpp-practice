#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {7,3,2,4,9,12,56};
    sort(arr,arr+7);
    // here children = 3  hence we need to check difference bw max and min element of every 3 elements
    int res = 100;
    for(int i=0; i<4;i++){
        if(arr[i+2]-arr[i] < res)
            res = arr[i+2]-arr[i];
    }
    cout<<res;
}