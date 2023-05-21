#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,5,3,8,12};
    int profit = 0;
    for(int i = 1; i< 5; i++){
        if(arr[i]>arr[i-1]){
            profit += arr[i]-arr[i-1];
        }
    }
    cout<<profit<<endl;
}