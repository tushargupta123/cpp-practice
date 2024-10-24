#include <bits/stdc++.h>
using namespace std;

// (x^n)%m

long long int PowMod(long long int x, long long int n, long long int M)
{
    long long ans = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            x = ((x % M) * (x % M)) % M;
            n /= 2;
        }
        else
        {
            ans = (ans * x) % M;
            n--;
        }
    }
    return ans;
}

int main(){
    cout<<PowMod(2,21,5);
}