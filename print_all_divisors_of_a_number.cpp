#include<bits/stdc++.h>
using namespace std;

// time complexity => O(sqrt(n))

int main(){
    int n;
    cin>>n;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<endl;
            if(n/i != i){
                cout<<(n/i)<<endl;
            }
        }
    }
}