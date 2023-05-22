#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,8,30,-5,20,7};
    int sum = 0,res = 0;
    for(int i=0;i<(sizeof(arr)/sizeof(int)); i++){
        if(i>=3){
            sum  = sum + arr[i] - arr[i-3];
            res = max(res,sum);
        }else{
            sum += arr[i];
        }
    }
    cout<<res;
}