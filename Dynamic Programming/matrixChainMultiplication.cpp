#include<iostream>
#include<limits.h>
using namespace std;

int mcm(int arr[],int n){
    int dp[n][n];
    for(int i=0;i<n-1;i++){
        dp[i][i+1] = 0;                 // bcs matrix with two dimesions left will have 0 multiplications
    }
    for(int gap=2;gap<n;gap++){
        for(int i=0;i+gap<n;i++){
            int j = i+gap;
            dp[i][j] = INT_MAX;
            for(int k=i+1;k<j;k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int arr[] = {2,1,3,4};
    cout<<mcm(arr,4);
}