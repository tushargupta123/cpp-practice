#include <iostream>
using namespace std;

int main()
{
    int arr[] = {20, 10, 30, 50, 5};
    for (int cs = 0; cs < 4; cs++)
    {
        int pos = cs;
        int item = arr[cs];
        for (int i = cs + 1; i < 5; i++)
        {
            if (arr[i] < item)
            {
                pos++;
            }
        }
        swap(item, arr[pos]);
        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < 5; i++)
            {
                if (arr[i] < item)
                {
                    pos++;
                }
            }
            swap(item, arr[pos]);
        }
    }
    for(int x: arr){
        cout<<x<<" ";
    }
}