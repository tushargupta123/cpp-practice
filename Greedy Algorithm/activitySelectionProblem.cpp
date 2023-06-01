#include<iostream>
using namespace std;

int main(){
    int arr[4][2] = {{1,3},{2,4},{3,8},{10,11}};
    int currStart = 0;
    int currEnd = 0;
    int res = 0;
    for(int i=0;i<4;i++){
        if(currStart < arr[i][0] && currEnd <= arr[i][0]){
            res++;
            currStart = arr[i][0];
            currEnd = arr[i][1];
        }
    }
    cout<<res;
}