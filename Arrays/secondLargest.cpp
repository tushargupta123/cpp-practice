#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,30,20,40};
    int max=0;
    int second_max=0;
    for(int i=0;i<4;i++){
        if(arr[i]<=arr[max] && arr[i]>=arr[second_max]){
            second_max=i;
        }else if(arr[i]>=arr[max]){
            second_max=max;
            max=i;
        }
    }
    cout<<second_max;
    return 0;
}