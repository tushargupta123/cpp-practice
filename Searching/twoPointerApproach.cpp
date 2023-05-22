#include<iostream>
using namespace std;

int main(){
    int arr[]={2,4,8,9,11,20,40};
    int left= 0,rt = 6,sum= 17;
    while(left<rt){
        if(arr[left]+arr[rt] == sum){
            cout<<arr[left]<<"+"<<arr[rt];
            break;
        }else if(arr[left]+arr[rt]>sum){
            rt--;
        }else{
            left++;
        }
    }
    return 0;
}