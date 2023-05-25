#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int arr[] = {10, 20, 20, 30, 40, 30, 20, 10};
    int k = 4;
    int n = sizeof(arr) / sizeof(int);
    unordered_map<int, int> m;
    for (int i = 0; i < k; i++)
    {
        m[arr[i]]++;
    }
    cout << m.size() << " ";
    for (int i = k; i < n; i++)
    {
        m[arr[i - k]]--;
        if (m[arr[i - k]] == 0)
        {
            m.erase(m.find(arr[i - k]));
        }
        m[arr[i]]++;
        cout << m.size() << " ";
    }
}