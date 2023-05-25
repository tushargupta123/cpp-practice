#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int arr[] = {2, 5, 8, 4, 3, 1};
    unordered_set<int> s;
    int res = 0, curr=1;
    for (int x : arr)
    {
        s.insert(x);
    }
    for (int i = 0; i < 6; i++)
    {   
        if(s.find(arr[i]-1) == s.end()) curr=1;
        while (s.find(arr[i] + curr) != s.end())
        {
            curr++;
        }
        res = max(res, curr);
    }
    cout<<res;
}