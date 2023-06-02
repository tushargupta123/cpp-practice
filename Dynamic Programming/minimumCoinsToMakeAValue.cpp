#include<iostream>
#include<limits.h>
using namespace std;

int minCoins(int coins[],int n,int sum){
    int dp[sum+1];
    dp[0] = 0;
    for(int i=1;i<=sum;i++){
        dp[i] = INT_MAX;
    }
    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            if(coins[j] <= i){
                int sub_res = dp[i-coins[j]];
                if(sub_res != INT_MAX){
                dp[i] = min(dp[i],1+sub_res);
                }
            }
        }
    }
    return dp[sum];
}

int main(){
    int coins[] = {3,4,1};
    int sum = 5;
    cout<<minCoins(coins,3,5);
}