#include <iostream> //queens on levels and nPr
#include <vector>
using namespace std;

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

void nqueens(vector<vector<bool>> &board, int current_queen, string as_of_now)
{
    if (current_queen > board.size())
    {
        cout << as_of_now << endl;
        return;
    }
    for (int current_box = 0; current_box < board.size() * board.size(); current_box++)
    {
        int i = current_box / board[0].size();
        int j = current_box % board[0].size();

        if (board[i][j] == 0 && is_the_queen_safe(board, i, j) == true)
        {
            board[i][j] = 1;
            nqueens(board, current_queen + 1, as_of_now + to_string(i) + to_string(j) + "_");
            board[i][j] = 0;
        }
    }
}

int main(int argc, char **argv)
{
    vector<vector<bool>> board{
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}

    };
    nqueens(board, 1, "");
}
