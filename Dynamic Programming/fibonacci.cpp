#include<iostream>
using namespace std;

// Memoization           => top down approach ( we got at lowest value and from there we start computing from bottom to up using previous value.)
// in fib(5) we call for fib(3) again even if it is calculated before so we are doing exponential work here.
// we can hence store of previously calculated value and use when asked for

int fib(int n,int memo[]){
    if(memo[n] == -1){
        if(n==0 || n==1){
            memo[n] = n; 
        }else{
            memo[n] = fib(n-1,memo)+fib(n-2,memo);
        }
    }
    return memo[n];
}

// Tabulation        => bottom up approach ( we calculate value from start and go till last)

int fibTab(int n){
    int f[n+1];
    f[0] = 0;
    f[1] = 1;
    for(int i=2; i<=n; i++){
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}

int main(){
    int n = 5;
    int memo[n+1];
    for(int i=0;i<=n;i++){
        memo[i] = -1;
    }
    cout<<fib(n,memo);
    cout<<endl<<fibTab(n);
}