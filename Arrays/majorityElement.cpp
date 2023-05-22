#include<iostream>
using namespace std;

int main(){
    int arr[]= {8,5,8,6,4,8,8};
    int res = 0, count =1;
    for(int i=0; i<7; i++){
        if(arr[res] == arr[i]){
            count++;
        }else{
            count--;
        }
        if(count == 0){
            res = i;
            count = 1;
        }
    }
    for(int i=0; i<7; i++){
        if(arr[res] == arr[i]){
            count++;
        }
    }
    if(count <= 3){
        cout<<"no majority";
    }else{
        cout<<res;
    }
}