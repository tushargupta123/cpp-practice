#include<iostream>
using namespace std;

int findMin(int a,int b, int c){
    if(a<=b && a<=c){
        return a;
    }else if(b<=a && b<=c){
        return b;
    }else{
        return c;
    }
}

// in this problem we can do three operations : insert , delete, replace and we have to do min operation so that both string become equal
// we start from end if character matches then we go ahead . else we do all three operations and check which operation give best result
// if we do insert then length of s1 remains same but length of s2 decreases ,
// if we do delete then length of s2 remians same but length of s1 decreases,
// if we do replace then length of both decreases because last chacacter of both matches

int editDistance(string s1,string s2,int n,int m){
    if(m==0) return n;
    if(n==0) return m;
    if(s1[n-1]==s2[m-1]){
        return editDistance(s1,s2,n-1,m-1);
    }else{
        return 1+findMin(editDistance(s1,s2,n-1,m),editDistance(s1,s2,n,m-1),editDistance(s1,s2,n-1,m-1));
    }
}

// DP solution

int editDistanceDP(string s1,string s2,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1+findMin(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string s1 = "Saturday";
    string s2 = "Sunday";
    cout<<editDistanceDP(s1,s2,s1.length(),s2.length());
}