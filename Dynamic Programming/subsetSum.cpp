#include<iostream>
using namespace std;

int subsetSum(int arr[],int sum,int n){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<arr[i-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int arr[] = {10,5,2,3,6};
    cout<<subsetSum(arr,8,5);
}