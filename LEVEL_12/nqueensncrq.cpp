#include <iostream> // queens on levels and then nCr
#include <vector>

bool is_the_queen_safe(vector<vector<bool>> &board, int i, int j)
{
    //horizontal
    for (int jj = 0; jj < board.size(); jj++)
    {
        if (board[i][jj] == true && jj != j) // jj!=j is checked to determine that the next queen doesnt check for the position at which already a queen is placed
        {
            return false;
        }
    }
    //vertical
    for (int ii = 0; ii < board.size(); ii++)
    {
        if (board[ii][j] == true && ii != i)
        {
            return false;
        }
    }
    //southeast
    for (int ii = i + 1, jj = j + 1; ii < board.size() && jj < board.size(); ii++, jj++)
    {
        if (board[ii][jj] == true)
        {
            return false;
        }
    }
    //southwest
    for (int ii = i + 1, jj = j - 1; ii < board.size() && jj >= 0; ii++, jj--)
    {
        if (board[ii][jj] == true)
        {
            return false;
        }
    }
    //northeast
    for (int ii = i - 1, jj = j + 1; ii >= 0 && jj < board.size(); ii--, jj++)
    {
        if (board[ii][jj] == true)
        {
            return false;
        }
    }
    //northwest
    for (int ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0; ii--, jj--)
    {
        if (board[ii][jj] == true)
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    vector<vector<bool>> board{
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}

    };
    nqueens(board, 1, -1, "");
}
