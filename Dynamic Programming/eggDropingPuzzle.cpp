#include<iostream>
#include<limits.h>
using namespace std;

int egg(int e,int f){
    int dp[f+1][e+1];
    for(int i=1;i<=e;i++){
        dp[1][i] = 1;   // if we have 1 floor then in we need only one test
        dp[0][i] = 0;   // if we have 0 floor then in we dont need to test
    }
    for(int i=1;i<=f;i++){
        dp[i][1] = i;    // if we have i floor and 1 egg then we have to start from 1st floor and test till x floor so in worst case we have to test till i times
    }
    for(int i=2; i<=f; i++){
        for(int j=2; j<=e; j++){
            dp[i][j] = INT_MAX;
            for(int x =1; x<=i ; x++){
                dp[i][j] = min(dp[i][j],1+             // adding one to result because we have tested for that floor and then we are proceeding
                max(dp[x-1][j-1],                       // if egg breaks from x floor then we have to check for floors below it
                dp[i-x][j]));                           // else we have to check from above floors
            }
        }
    }
    return dp[f][e];
}

int main(){
    int f = 10;
    int e = 2;
    cout<<egg(e,f);
}