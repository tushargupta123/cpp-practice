#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> v{5, 15, 10, 8, 6, 12, 9, 18};
  stack<int> s;
  s.push(1);
  int n = v.size();
  for (int i = 1; i < n; i++)
  {

    if (v[i-1] > v[s.top()])
    {
      s.push(i);
      cout << v[s.top()] << " ";
    }

    else
    {
      int k = i;
      while (v[i-1] > v[s.top()])
      {
        s.push(++k);
      }
      s.push(++k);
      cout << v[s.top()] << " ";
    }
  }
}


void printDistWind(int arr[],int n,int k)

for()