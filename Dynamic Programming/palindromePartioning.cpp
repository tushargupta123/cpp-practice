#include<iostream>
#include<limits.h>
using namespace std;

bool isPalindrome(string &str,int start,int end){
    if(start>end){
        return true;
    }else{
        if(str[start]==str[end]){
            isPalindrome(str,start+1,end-1);
        }else{
            return false;
        }
    }
}

int palPar(string s){
    int n = s.length();
    int dp[n][n];
    for(int i=0; i<n; i++){
        dp[i][i] = 0;                    // bcs string with single character is always palindrome
    }
    for(int gap=1;gap<n;gap++){
        for(int i=0; i+gap<n; i++){
            int j = i+gap;
            if(isPalindrome(s,i,j)){
                dp[i][j] = 0;
            }else{
                dp[i][j] = INT_MAX;
                for(int k=i;k<j;k++){
                    dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    string s1 = "geek";
    cout<<palPar(s1);
}