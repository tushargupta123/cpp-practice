#include<iostream>
#include<limits.h>
using namespace std;

int sum(int arr[],int start,int end){
    int res = 0;
    for(int i=start; i<=end; i++){
        res += arr[i];
    }
    return res;
}

int minPages(int arr[],int k,int n){
    int dp[k+1][n+1];
    for(int i=1;i<=n;i++){
        dp[1][i] = sum(arr,0,i-1);
    }
    for(int i=1;i<=k;i++){
        dp[i][1] = arr[0];
    }
    for(int i=2;i<=k;i++){
        for(int j=2;j<=n;j++){
            dp[i][j] = INT_MAX;
            for(int p=1;p<j;p++){
                dp[i][j] = min(dp[i][j],max(dp[i-1][p],sum(arr,p,j-1)));
            }
        }
    }
    return dp[k][n];
}

int main(){
    int arr[] = {10,20,30,40};
    int k = 2;
    cout<<minPages(arr,k,4);
}