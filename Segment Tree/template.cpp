#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> seg;
    public:
        SegmentTree(int n){
            seg.resize(4 * n);
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

        void update(int idx, int low, int high, int i, int val){
            if(low == high){
                seg[idx] = val;
                return;
            }
            int mid = (low + high) >> 1;
            if(i <= mid){
                update(2 * idx + 1, low, mid, i, val);
            } else {
                update(2 * idx + 2, mid + 1, high, i, val);
            }
            seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
        }
};

int main(){
    vector<int> arr = {2,1,0,4,5};
    int n = arr.size();
    SegmentTree sg(n);
    sg.build(0,0,n-1,arr);
    cout<<sg.query(0,0,n-1,0,3)<<endl;
    sg.update(0,0,n-1,2,3);
    cout<<sg.query(0,0,n-1,0,3)<<endl;
}