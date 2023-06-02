#include <iostream>
using namespace std;

// we have to generate longest subsequence which has increasing value.

// O(n^2)
int LIS(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    int res = lis[0];
    for (int i = 0; i < n; i++)
    {
        res = max(lis[i], res);
    }
    return res;
}

// O(n log n)

int ceil(int tail[], int s, int e, int x) {
    while (e >= s) {
        int m = s + (e - s) / 2;
        if (tail[m] >= x) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return s;
}

int LISDP(int arr[], int n) {
    int tail[n];
    tail[0] = arr[0];
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > tail[len - 1]) {
            tail[len] = arr[i];
            len++;
        } else {
            int c = ceil(tail, 0, len - 1, arr[i]);
            tail[c] = arr[i];
        }
    }
    return len;
}

int main() {
    int arr[] = {3, 4, 2, 8, 10, 5, 1};
    cout << LISDP(arr, 7) << endl;
    return 0;
}

// Variations in LIS

// 1. mininmum deletions to make array sorted
// we can calculate lis and then result will be n - lis.

// 2. maximum sum increasing subsequence
// Q . we have to find increasing subsequence with max sum not with max elements
// A . we will have same code but instead of adding 1 to result so that we can find lis we have to add element in tail array and then res will be the max sum found

// 3. maximum length biotonic subsequence
// Q . we have to find subsequence which is first increasing and then decreasing
// A . we will find lis and the lds (run same code from end of array) and then res = max(res,lis[i]+lds[i]-1)
