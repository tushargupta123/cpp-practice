#include <iostream>
using namespace std;

bool isSafe(int i,int j,int n,int grid[4][4]){
    for(int k=0; k<4 ; k++){
        if(grid[i][k]==n || grid[k][j]==n){
            return false;
        }
    }
    int s = 2;
    int rs = i-i%2;
    int cs = j-j%2;
    for(int x=0; x<s ;x++){
        for(int y=0 ;y<s ;y++){
            if(grid[x+rs][y+cs]==n){
                return false;
            }
        }
    }
    return true;
}

bool solve(int grid[4][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (grid[i][j] == 0)
            {
                break;
            }
        }
    }
    if (i == 4 && j==4)
    {
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    for (int n = 1; n <= 4; n++)
    {
        if (isSafe(i, j, n, grid))
        {
            grid[i][j] = n;
            if (solve(grid))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int grid[4][4] = {{1, 0, 3, 0},
                      {0, 0, 2, 1},
                      {0, 1, 0, 2},
                      {2, 4, 0, 0}};
    solve(grid);
}