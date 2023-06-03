// size of array for segment tree
// size  = 2*2^(ceil(log2 n)) - 1 < 4n         so we always make array of size 4n .
// if n = power of 2 then size  = 2n-1

// we take array and divide it into two parts at each step if new node has even terms then divide it into equal parts else take 1 more in left
#include<iostream>
#include<vector>
using namespace std;

vector<int> tree;

int constructST(int ss, int se, int si, int arr[]) {
    if (ss == se) {
        tree[si] = arr[ss];
        return arr[ss];
    }
    int mid = ss + ((se - ss) / 2);
    tree[si] = constructST(ss, mid, ((2 * si )+ 1), arr) + constructST(mid + 1, se, ((2 * si )+ 2), arr);
    return tree[si];
}

int getSumRec(int qs,int qe,int ss, int se,int si){
    if(ss > qe || se < qs)  return 0;
    if(se <= qe && ss >= qs)    return tree[si];
    int mid = ss + ((se - ss) / 2);
    return getSumRec(qs,qe,ss,mid,((2*si)+1))+getSumRec(qs,qe,mid+1,se,((2*si)+2));
}

void getSum(int qs, int qe, int n) {
    int ss = 0;
    int se = n - 1;
    int si = 0;
    cout << getSumRec(qs, qe, ss, se, si);
}

void updateRec(int ss,int se,int si,int i,int diff){
    if(i<ss || i>se) return;
    tree[si] += diff;
    if(se>ss){
        int mid = ss + ((se - ss) / 2);
        updateRec(ss,mid,(2*si)+1,i,diff);
        updateRec(mid+1,se,(2*si)+2,i,diff);
    }
}

void update(int val,int i,int arr[],int n){
    int diff = val - arr[i];
    int ss = 0;
    int se = n-1;
    int si = 0;
    updateRec(ss,se,si,i,diff);
}


int main(){
    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    tree.resize(4 * n);
    cout<<constructST(0,n-1,0,arr)<<endl;
    getSum(0,1,n);
    update(50,0,arr,n);
    cout<<endl;
    getSum(0,1,n);
}