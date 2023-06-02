#include <iostream>
using namespace std;

// Memoization method

int lcs(string s1, string s2, int m, int n, int memo[5][6])
{
    if (memo[m][n] != -1)
    {
        return memo[m][n];
    }
    if (m == 0 || n == 0)
    {
        memo[m][n] = 0;
        return 0;
    }
    else
    {
        if (s1[m - 1] == s2[n - 1])
        {
            memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);
        }
        else
        {
            memo[m][n] = max(lcs(s1, s2, m - 1, n, memo), lcs(s1, s2, m, n - 1, memo));
        }
    }
    return memo[m][n];
}

// Tabulation method

int lcsTab(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1];

    // filling first row and column 0
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s1 = "ABCD";
    string s2 = "BXCAY";
    int n = s1.length();
    int m = s2.length();
    int memo[5][6];
    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            memo[i][j] = -1;
        }
    }
    // cout << lcs(s1, s2, n, m, memo);
    cout << lcsTab(s1, s2);
}

// Variation is LCS

// 1. shortest common supersequence
// Q . we have to take two strings and make a new string which has all the characters of both the strings 
// A . we will find the lcs and add left out characters from both strings

// 2. Longest palindromic subsequence
// Q . we have to tell subsequence which is palindrome in that string
// A . we will make another string s2 which is reverse of s1 and then find lcs .

// 3. Longest repeating subsequence
// Q . we have to find longest set of repeating characters in string s1.
// A . we will make another string s2 same as s1 and then find lcs also add another condition that if any character matches then their index should be equal

