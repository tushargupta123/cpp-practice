#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<vector<int>> seg;

public:
    SegmentTree(int n)
    {
        seg.resize(4 * n, vector<int>(3, 0));
    }

    void build(int idx, int low, int high, string &s)
    {
        if (low == high)
        {
            if (s[low] == '(')
            {
                seg[idx][0]++;
            }
            else
            {
                seg[idx][1]++;
            }
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * idx + 1, low, mid, s);
        build(2 * idx + 2, mid + 1, high, s);
        int full = min(seg[2 * idx + 1][0], seg[2 * idx + 2][1]);
        seg[idx][2] = full + seg[2 * idx + 1][2] + seg[2 * idx + 2][2];
        seg[idx][0] = seg[2 * idx + 1][0] + seg[2 * idx + 2][0] - full;
        seg[idx][1] = seg[2 * idx + 1][1] + seg[2 * idx + 2][1] - full;
    }

    vector<int> query(int idx, int low, int high, int l, int r)
    {
        if (r < low || l > high)
        {
            return {0, 0, 0};
        }
        if (l <= low && r >= high)
        {
            return seg[idx];
        }
        int mid = (low + high) >> 1;
        vector<int> left = query(2 * idx + 1, low, mid, l, r);
        vector<int> right = query(2 * idx + 2, mid + 1, high, l, r);

        int full = min(left[0], right[1]);
        vector<int> res(3, 0);
        res[2] = full + left[2] + right[2];
        res[0] = left[0] + right[0] - full;
        res[1] = left[1] + right[1] - full;
        return res;
    }
};

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    int sz = s.size();
    
    SegmentTree sg(sz);
    sg.build(0, 0, sz - 1, s);

    while (n--)
    {
        int i, j;
        cin >> i >> j;
        i--;
        j--;
        cout << sg.query(0, 0, sz - 1, i, j)[2] * 2 << endl;
    }

    return 0;
}
