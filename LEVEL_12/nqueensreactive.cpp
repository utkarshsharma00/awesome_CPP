#include <iostream> //* Reactive Calls
#include <vector>
using namespace std;

int count = 0;
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
    
}    

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

void nqueens(vector<vector<bool>> &board, int current_queen, int last_queen_placed_in_which_box, string as_of_now)
{
    if (current_queen == board.size())
    {

        if (is_the_box_safe(board) == true)
        {
            count++;
            cout << as_of_now << endl;
        }
        // count++;
        return;
    }
    for (int current_box = last_queen_placed_in_which_box + 1; current_box < board.size() * board.size(); current_box++)
    {
        int i = current_box / board[0].size();
        int j = current_box % board[0].size();

        if (board[i][j] == 0)
        {
            board[i][j] = 1;
            nqueens(board, current_queen + 1, current_box, as_of_now + to_string(i) + to_string(j) + "_");
            board[i][j] = 0;
        }
    }
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
