#include <iostream>
#include <unordered_set>
using namespace std;

bool isPair()
{
    int arr[] = {3, 1, 8, 15, -8};
    int sum = 17;
    unordered_set<int> st;
    st.insert(arr[0]);
    for (int i = 1; i < 5; i++)
    {
        if (st.find(sum - arr[i]) == st.end())
        {
            return true;
        }
        else
        {
            st.insert(arr[i]);
        }
    }
    return false;
}

int main()
{
    if(isPair()) 
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}