#include<iostream>
using namespace std;

int main(){
    bool arr[] = {1,1,0,0,0,1,1,1,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 1; i<n; i++){
        if(arr[i] != arr[i-1]){
            if(arr[i] != arr[0]){
            cout<<"From "<<i<<" to ";
            }else{
                cout<<i<<endl;
            }
    }
    }
    if(arr[n-1] != arr[0]){
        cout<<n-1;
    }
}