#include<iostream>
using namespace std;

int main(){
    int arr[]={7,10,13,14};
    bool flag = (arr[0]%2==0 ? true : false);
    int res=1;
    for(int i=1; i<5;i++){
        if((arr[i]%2==0 && !flag) || (arr[i]%2!=0 && flag)){
            res++;
            flag=!flag;
        }else{
            flag =(arr[i]%2==0 ? true : false);
        }
    }
    cout<<res;
}