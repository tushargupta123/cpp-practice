#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> seg,lazy;
    public:
        SegmentTree(int n){
            seg.resize(4 * n);
            lazy.resize(4 * n);
        }

        void build(int idx, int low, int high, vector<int> &arr){
            if(low == high){
                seg[idx] = arr[low];
                return;
            }
            int mid = (low + high) >> 1;
            build(2 * idx + 1, low, mid, arr);
            build(2 * idx + 2, mid + 1, high, arr);
            seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
        }

        int query(int idx, int low, int high, int l,int r){
            if(lazy[idx]!=0){
                seg[idx] += lazy[idx];
                if(high!=low){
                    lazy[2*idx+1]+=lazy[idx];
                    lazy[2*idx+2]+=lazy[idx];
                }
                lazy[idx]=0;
            }
            if(r < low || l > high) {
                return INT_MAX;
            }
            if(l <= low && r >= high){
                return seg[idx];
            }
            int mid = (low + high) >> 1;
            int left = query(2 * idx + 1, low, mid, l, r);
            int right = query(2 * idx + 2, mid+1, high, l, r);
            return min(left, right);
        }

        void update(int idx, int low, int high, int l, int r, int val){
            if(lazy[idx]!=0){
                seg[idx] += lazy[idx];
                if(high!=low){
                    lazy[2*idx+1]+=lazy[idx];
                    lazy[2*idx+2]+=lazy[idx];
                }
                lazy[idx]=0;
            }
            if(r < low || l > high){
                return;
            }
            if(l<=low && r>=high){
                seg[idx] += val;
                if(low!=high){
                    lazy[2*idx+1]+=val;
                    lazy[2*idx+2]+=val;
                }
                return;
            }
            int mid = (low + high) >> 1;
            update(2 * idx + 1, low, mid, l, r, val);
            update(2 * idx + 2, mid + 1, high, l, r, val);
            seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
        }
};

int main(){
    vector<int> arr = {2,1,0,4,5};
    int n = arr.size();
    SegmentTree sg(n);
    sg.build(0,0,n-1,arr);
    cout<<sg.query(0,0,n-1,0,3)<<endl;
    sg.update(0,0,n-1,1,3,3);
    cout<<sg.query(0,0,n-1,0,3)<<endl;
}