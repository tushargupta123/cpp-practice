#include<iostream>
using namespace std;

int main(){
    int arr[] = {3,4,8,-9,20,6};
    int sum = 0,l_sum=0;
    int found = false;
    for(int x:arr){
        sum+= x;
    }
    for(int i = 0; i < 6; i++){
        if(l_sum==sum-arr[i]){
            found=true;
        }
        l_sum+=arr[i];
        sum-=arr[i];
    }
    if(found){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}