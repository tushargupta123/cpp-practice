#include<iostream>
#include<vector>
using namespace std;

int josephus(int n,int k){
    if(n==1){
        return 0;
    }else{
        return (josephus(n-1,k)+k)%n;
    }
}

int main(){
    cout<<josenphus(5,3);
    return 0;
}