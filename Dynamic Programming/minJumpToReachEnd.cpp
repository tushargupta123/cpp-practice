#include<iostream>
#include<limits.h>
using namespace std;

int minJump(int arr[],int n){
    int dp[n];
    dp[0] = 0;
    for(int i=1;i<n;i++){
        dp[i] = INT_MAX;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]+j >= i){          // if we can go to i from j
                if(dp[j]!=INT_MAX){             // if we can reach here(j) by previous jumps or not
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
    }
    return dp[n-1];
}

int main(){
    int arr[] = {3,4,2,1,2,1};
    cout<<minJump(arr,6);
}