#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,4,4,4,1,0,1};
    int k = 5;
    int count[7] = {0};
    for(int i=0;i<7;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<7;i++){
        count[i] += count[i-1];
    }
    int output[7];
    for(int i=0;i<7;i++){
        output[count[arr[i]] -1] = arr[i];
        count[arr[i]]--;
    }
    for(int x:output){
        cout<<x<<" ";
    }
    return 0;
}