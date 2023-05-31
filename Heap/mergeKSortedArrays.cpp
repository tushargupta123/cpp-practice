#include<iostream>
#include<queue>
using namespace std;

struct Triplet{
    int val,aPos,vPos;
    Triplet(int c,int ap, int vp){
        val = c;
        aPos = ap;
        vPos = vp;
    }
};

struct MyComp{
    bool operator()(Triplet &a,Triplet &b){
        return a.val > b.val;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &arr){
    vector<int> res;
    priority_queue<Triplet,vector<Triplet>,MyComp> pq;
    for(int i=0;i<arr.size();i++){
        Triplet t = {arr[i][0],i,0};
        pq.push(t);
    }
    while(!pq.empty()){
        Triplet curr = pq.top();
        pq.pop();
        int ap = curr.aPos;
        int vp = curr.vPos;
        if(vp+1 < arr[ap].size()){
            Triplet t = {arr[ap][vp+1],ap,vp+1};
            pq.push(t);
        }
    }
    return res;
}

int main(){
    vector<vector<int> > arr{ { 2, 6, 12 },
                            { 1, 9 },
                            { 23, 34, 90, 2000 } };
    vector<int> res = mergeKSortedArrays(arr);
    for(auto x:arr){
        cout<<x<<" ";
    }
}