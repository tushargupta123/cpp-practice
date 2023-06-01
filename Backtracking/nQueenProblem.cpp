#include <iostream>
using namespace std;

bool isSafe(int row, int col, bool board[4][4])
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    for (int i = row, j = col; j >= 0 && i < 4; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

bool solveRec(int col, bool board[4][4])
{
    if (col == 4)
    {
        return true;
    }
    for (int i = 0; i < 4; i++)
    {
        if (isSafe(i, col, board))
        {
            board[i][col] = true;
            if (solveRec(col + 1, board))
            {
                return true;
            }
            board[i][col] = false;
        }
    }
    return false;
}

bool solve(bool board[4][4])
{
    if (!solveRec(0, board))
    {
        return false;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
}

int main()
{
    bool board[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = false;
        }
    }
    cout << solve(board);
}