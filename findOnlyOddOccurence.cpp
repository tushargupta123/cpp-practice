#include<iostream>
using namespace std;

int main(){
    int arr[] = {3,4,5,3,4,5,3};
    int res = 0;
    for(int x: arr){
        res = res ^ x;
    }
    cout<<res;
}