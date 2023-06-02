#include<iostream>
using namespace std;

// we have even number of values we have first chance to pick any value from start or from end and then opponent will pick from start or end of remaining values
// we have to ensure that we win

int sol(int arr[],int n){
    int dp[n][n];
    for(int i = 0; i < n-1;i++){
        dp[i][i+1] = max(arr[i],arr[i+1]);
    }
    for(int gap=3; gap < n; gap=gap+2){
        for(int i=0; i+gap<n; i++){
            int j= i+gap;
            dp[i][j] = max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]), arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
        }
    }
    return dp[0][n-1];
}

int main(){
    int arr[] = {20,5,4,6,8,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<sol(arr,n);
}