#include<iostream>
using namespace std;
bool isPrime(int x){
    for(int i = 2; i<x; i++){
        if(x%i == 0){
            return false;
    }
    }
    return true;
}

void primeFactorization(int n){
    for(int i = 2; i<=n; i++){
        if(isPrime(i)){
            int x =i;
            while(n%x == 0){
            cout<<i<<",";
            x=x*i;
            }
        }
    }
}

int main(){
    primeFactorization(100);
    return 0;
}