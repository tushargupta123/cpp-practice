#include<iostream>
using namespace std;

int maxCut(int rope,int a, int b, int c){
    int dp[rope+1];
    dp[0] = 0;
    for(int i=1;i<=rope;i++){
        dp[i] = -1;
        if(i-a >=0 ) dp[i] = max(dp[i],dp[i-a]);
        if(i-b >=0 ) dp[i] = max(dp[i],dp[i-b]);
        if(i-c >=0 ) dp[i] = max(dp[i],dp[i-c]);
        if(dp[i]!=-1){
            dp[i]++;
        }
    }
    return dp[rope];
}

int main(){
    int rope=5;
    cout<<maxCut(rope,1,2,3);
}