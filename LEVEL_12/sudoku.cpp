#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sudoku(vector<vector<int>> &board, int box_no)
{
    if (box_no == board.size() * board.size()) // see carefully for assignment and comparison operators and logic
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    int i = box_no / board.size(); // i = rows
    int j = box_no % board.size(); // j = cols
    if (board[i][j] == 0)
    {
        for (int possible_options = 1; possible_options <= 9; possible_options++)
        {
            if (is_the_number_safe(board, i, j, possible_options) == true)
            {
                board[i][j] = possible_options;
                sudoku(board, box_no + 1);
                board[i][j] = 0;
            }
        }
    }
    else
    {
        sudoku(board, box_no + 1); //place is filled with the correct option, directly jump to the next
    }
}

int main(int argc, char **argv)
{
    vector<vector<int>> board{
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0},
    };
    sudoku(board, 0);
}
