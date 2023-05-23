#include <iostream>
using namespace std;

int main()
{
    int arr1[] = {3, 5, 10, 10, 10, 15, 20};
    int arr2[] = {3, 7, 10, 15};
    int n = sizeof(arr1) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);
    int i = 0, j = 0;
    while (i < n && j < m)
    {

        if (i > 0 && arr1[i] == arr1[i - 1])
        {   
            i++;
            continue;
        }
        if (j > 0 && arr2[j] == arr2[j - 1])
        {
            j++;
            continue;
        }
        if (arr1[i] == arr2[j])
        {
            cout << arr2[j] << " ";
            j++;
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            cout << arr2[j] << " ";
            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
        }
        while (i < n)
        {
            if (i > 0 && arr1[i] != arr1[i - 1])
            {
                cout << arr1[i] << " ";
                i++;
            }
        }
        while (j < m)
        {
            if (j > 0 && arr2[j] != arr2[j - 1])
            {
                cout << arr2[j] << " ";
                j++;
            }
        }
    }
}