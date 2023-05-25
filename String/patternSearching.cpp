#include <iostream>
using namespace std;

// Robin Karp method    -> O((n-m+1)*m)       => n = length of string, m = length of pattern
void rbSearch(string txt, string pat, int n, int m)
{
    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    int p = 0, t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pat[i]) % q;   // this will remain same 
        t = (t * d + txt[i]) % q;   // this will change according to rolling hash
    }
    // generating hash for pattern using hash function h = x1.d^(m-1)+x2.d^(m-2)..... ,    using q if there are long values and we dont want to make a long hash table
    for (int i = 0; i < n - m; i++)
    {
        if (p == t)         // if hash of both matches then only we will check for elements
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (pat[j] != txt[j + i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)       // if all characters matches then we will print the index
            {
                cout << i << " ";
            }
        }
        if (i < n - m)
        {
            t = ((d * (t - txt[i] * h)) + txt[i + h]) % q;
            // here we used rolling hash
            // in rolling hash we generate hash for next element using hash of previous element by subtracting that element and adding next element
            if (t < 0)
            {
                t = t + q;
            }
        }
    }
}

int main()
{
    // naive implementation              -> O((n-m+1)*m)       => n = length of string, m = length of pattern
    string str = "abababcd";
    string pat = "abab";
    for (int i = 0; i < (str.length() - pat.length()); i++)
    {
        int j;
        for (j = 0; j < pat.length(); j++)
        {
            if (str[i + j] != pat[j])
            {
                break;
            }
        }
        if (j == (pat.length()))
        {
            cout << i << " ";
        }
    }
    cout << endl;

    // improved naive algorithm but here character in patern must be distinct        -> O(n)       => n = length of string
    string pat_2 = "ab";
    for (int i = 0; i < (str.length() - pat_2.length());)
    {
        int j;
        for (j = 0; j < pat_2.length(); j++)
        {
            if (str[i + j] != pat_2[j])
            {
                break;
            }
        }
        if (j == 0)
        {
            i++;
        }
        else
        {
            i = i + j;
        }
        if (j == (pat_2.length()))
        {
            cout << i << " ";
        }
    }
}