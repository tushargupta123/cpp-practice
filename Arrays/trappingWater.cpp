#include<iostream>
using namespace std;

int main(){
    int arr[5] = {5,0,6,2,3};
    int lmax[5],rmax[5],res=0;
    lmax[0]=arr[0];
    rmax[4] = arr[4];
    for(int i=1; i<5;i++){
        lmax[i] = max(lmax[i-1],arr[i]);
    }
    for(int i=3;i>=0;i--){
        rmax[i] = max(rmax[i+1],arr[i]);
    }
    for(int i=1;i<4;i++){
        res += (min(lmax[i],rmax[i])) - arr[i];
    }
    cout<<res;
}