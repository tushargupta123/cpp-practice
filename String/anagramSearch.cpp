#include <iostream>
using namespace std;

int main()
{
    string str = "geeksforgeeks";
    string pat = "frog";
    int strArr[256] = {0}, patArr[256] = {0};
    for (int i = 0; i < pat.length(); i++)
    {
        strArr[str[i]]++;
        patArr[pat[i]]++;
    }
    for (int i = pat.length(); i < str.length(); i++)
    {
        for (int j = 0; j < 256; j++)
        {
            if (strArr[j] != patArr[j])
            {
                strArr[str[i]]--;
                strArr[str[i - pat.length()]]++;
            }
            else
            {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}