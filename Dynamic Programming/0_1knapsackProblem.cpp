#include<iostream>
using namespace std;

int knapsack(int val[],int wt[] ,int w,int n){
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=w;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
        }
    }
    return dp[n][w];
}

int main(){
    int wt[] = {5,4,6,3};
    int val[] = {10,40,30,50};
    int w = 10;
    int n = 4;
    cout<<knapsack(val,wt,w,n);
}