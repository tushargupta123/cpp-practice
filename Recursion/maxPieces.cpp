#include<iostream>
using namespace std;

int find_max(int a,int b,int c){
    if(a>=b && a>=c){
        return a;
    }else if(b>=a && b>=c){
        return b;
    }else{
        return c;
    }
}

int maxPieces(int n,int a,int b, int c) {
    if(n==0) return 0;
    if(n<0) return -1;
    int res = find_max(maxPieces(n-a,a,b,c),maxPieces(n-b,a,b,c),maxPieces(n-c,a,b,c));
    if(res==-1) return -1;
    return res+1;
}

int main(){
    cout<<maxPieces(23,11,9,12);
    return 0;
}