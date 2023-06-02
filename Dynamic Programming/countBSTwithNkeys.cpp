#include<iostream>
using namespace std;

int count(int n){
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        for(int j=0;j<i;j++){
            dp[i] += dp[j]*dp[i-j-1];       // for every value we consider combinations of value less than key on left side and others on right side
        }
    }
    return dp[n];
}

int main(){
    int n = 5;
    cout<<count(5);
}