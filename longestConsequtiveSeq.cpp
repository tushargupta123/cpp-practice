#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int arr[] = {1, 9, 3, 4, 2, 20};
    unordered_set<int> s;
    int res = 0;
    for (int i = 0; i < 5; i++)
    {
        s.insert(arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        if (s.find(arr[i] - 1) != s.end())
        {
            continue;
        }
        else
        {
            int curr = 1;
            while (s.find(arr[i] + curr) != s.end())            // s.find() gives address of that element we can check whether by equting the s.find() != s.end() it means that if element is gound then its address would be not at s.end() i.e not in that set as s.end() returns the address just after the end of set. hence if s.find() == s.end() it means that after traversal of set element is not found.
            {
                curr++;
            }
            res = max(res, curr);
        }
    }
    cout << res;
}