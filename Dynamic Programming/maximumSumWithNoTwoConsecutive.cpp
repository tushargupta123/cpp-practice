#include <iostream>
#include <limits.h>
using namespace std;

int maxSum(int arr[], int n)
{
    int prev_prev = arr[0];
    int prev = max(arr[0], arr[1]);
    int res = prev;
    for (int i = 3; i <= n; i++)
    {
        res = max(prev,                    // if we dont include the element
                  prev_prev + arr[i - 1]); // if we include the element then sum would be that element + sum of previous non consecutive index in dp array
        prev_prev = prev;
        prev = res;
    }
    return res;
}

int main()
{
    int arr[] = {8, 7, 6, 10};
    cout << maxSum(arr, 4);
}