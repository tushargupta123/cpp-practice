#include<bits/stdc++.h>
using namespace std;

// (x^n) in O(log n) time

int main(){
    int x = 2,n = 21;
    int ans = 1;
    while(n>0){
        if(n%2==0){
            x*=x;
            n/=2;
        }else{
            ans*=x;
            n--;
        }
    }
    cout<< ans;
}