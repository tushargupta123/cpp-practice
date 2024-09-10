#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> seg, lazy;
public:
    SegmentTree(int n) {
        seg.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(int idx, int low, int high, vector<int> &arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void propagate(int idx, int low, int high) {
        if (lazy[idx] != 0) {
            seg[idx] = (high - low + 1) - seg[idx];
            if (low != high) {
                lazy[2 * idx + 1] ^= 1;
                lazy[2 * idx + 2] ^= 1;
            }
            lazy[idx] = 0;
        }
    }

    int query(int idx, int low, int high, int l, int r) {
        propagate(idx, low, high);
        if (r < low || l > high) {
            return 0;
        }
        if (l <= low && r >= high) {
            return seg[idx];
        }
        int mid = (low + high) >> 1;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }

    void update(int idx, int low, int high, int l, int r) {
        propagate(idx, low, high);
        if (r < low || l > high) {
            return;
        }
        if (l <= low && r >= high) {
            seg[idx] = (high - low + 1) - seg[idx];
            if (low != high) {
                lazy[2 * idx + 1] ^= 1;
                lazy[2 * idx + 2] ^= 1;
            }
            return;
        }
        int mid = (low + high) >> 1;
        update(2 * idx + 1, low, mid, l, r);
        update(2 * idx + 2, mid + 1, high, l, r);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
};

int main() {
    vector<int> arr = {1, 1, 0, 0, 1};
    int n = arr.size();
    SegmentTree sg(n);
    sg.build(0, 0, n - 1, arr);
    cout << sg.query(0, 0, n - 1, 0, 3) << endl;
    sg.update(0, 0, n - 1, 1, 3);
    sg.update(0, 0, n - 1, 0, 2);
    cout << sg.query(0, 0, n - 1, 0, 3) << endl;
}
