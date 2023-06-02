// size of array for segment tree
// size  = 2*2^(ceil(log2 n)) - 1 < 4n         so we always make array of size 4n .
// if n = power of 2 then size  = 2n-1

// we take array and divide it into two parts at each step if new node has even terms then divide it into equal parts else take 1 more in left
#include<iostream>
using namespace std;

int constructST(int ss,int se,int si,int tree[],int arr[]){
    if(ss == se){
        tree[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss+se)/2;
    tree[si] = constructST(ss,mid,2*si+1,tree,arr)+constructST(mid+1,se,2*si+2,tree,arr);
    return tree[si];
}

int main(){
    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int tree[4*n] = {0};
    cout<<constructST(0,n-1,0,tree,arr);
}