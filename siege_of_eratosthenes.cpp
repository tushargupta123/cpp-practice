#include<bits/stdc++.h>
using namespace std;

// time complexity => O(n log(log n))

int main(){
    int n;
    cin>>n;
    vector<bool> primes(n+1,true);
    for(int i=2;i*i<=n;i++){
        if(!primes[i]){
            continue;
        }
        for(int j=i*i;j<=n;j+=i){
            primes[j]=false;
        }
    }
    for(int i=2;i<=n;i++){
        if(primes[i]){
            cout<<i<<endl;
        }
    }
}