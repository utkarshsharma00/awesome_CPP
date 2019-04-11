#include <iostream> //* Proactive
#include <vector>
using namespace std;

bool is_the_box_safe(vector<vector<bool>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[i][j] == true)
            {
                if (is_the_queen_safe(board, i, j) == false)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    vector<vector<bool>> board = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},

    };
    nqueens(board, 0, -1, "");
    cout << count;
}
