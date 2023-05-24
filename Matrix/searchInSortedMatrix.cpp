#include<iostream>
using namespace std;

int main(){
    int arr[4][4] = {10,20,30,40,15,25,35,45,27,29,37,48,32,33,39,50};
    int ele = 29;
    int i= 3,j=0;   // begin from top right corner
    while(j<4 && i>=0){
    if(arr[i][j] == ele){
        cout<<"Found at : ("<<i<<","<<j<<")";
        break;
    }else if(arr[i][j] > ele){
        i--;            // if ele < current element move left       as array is row wise sorted
    }else{
        j++;            // if ele > current element move down       as array is column wise sorted
    }   
    }
    
}