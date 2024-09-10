#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
    public:
        vector<int> seg;
        SegmentTree(int n){
            seg.resize(4 * n);
        }

        void build(int idx, int low, int high, vector<int> &arr,int orr){
            if(low == high){
                seg[idx] = arr[low];
                return;
            }
            int mid = (low + high) >> 1;
            build(2 * idx + 1, low, mid, arr, !orr);
            build(2 * idx + 2, mid + 1, high, arr, !orr);
            if(orr){
                seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
            }else{
                seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
            }
        }

        void update(int idx, int low, int high, int i, int val, int orr){
            if(low == high){
                seg[idx] = val;
                return;
            }
            int mid = (low + high) >> 1;
            if(i <= mid){
                update(2 * idx + 1, low, mid, i, val, !orr);
            } else {
                update(2 * idx + 2, mid + 1, high, i, val, !orr);
            }
            if(orr){
                seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
            }else{
                seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
            }
        }
};

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int num = pow(2,n);
    vector<int> arr(num);
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    SegmentTree sg(4 * num);
    sg.build(0,0,num-1,arr,n%2);
    while(m--){
        int i,val;
        cin>>i;
        cin>>val;
        i--;
        sg.update(0,0,num-1,i,val,n%2);
        cout<<sg.seg[0]<<endl;
    }
    return 0;
}