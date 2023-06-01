#include<iostream>
using namespace std;

// recursive solution
int coinChange(int coin[],int n,int sum){
    if(sum == 0)    return 1;
    if(n==0)    return 0;
    int res = coinChange(coin,n-1,sum);
    if(coin[n-1]<=sum){
        res += coinChange(coin,n,sum-coin[n-1]);
    }
    return res;
}

// tabular method
int coinChangeTab(int coin[],int n,int sum){
    int dp[sum+1][n+1];
    for(int i = 1; i<= sum; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j<= n; j++){
        dp[0][j] = 1;
    }
    for(int i=1; i<=sum; i++){
        for(int j=1; j<=n;j++){
            dp[i][j] = dp[i][j-1];
            if(coin[j-1] <= i){
                dp[i][j] += dp[i-coin[j-1]][j];
            }
        }
    }
    return dp[sum][n];
}

int main(){
    int coin[] = {2,5,3,6};
    cout<<coinChangeTab(coin,4,10);
}