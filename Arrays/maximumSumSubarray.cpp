#include<iostream>
using namespace std;

int main(){
    int arr[] = {-3,8,-2,4,-5,6};
    int maxEnding = arr[0];
    int res=arr[0];
    for(int i = 1; i<6; i++){
        maxEnding = max(maxEnding+arr[i],arr[i]);
        res = max(maxEnding,res);
    }
    cout<<res;
}