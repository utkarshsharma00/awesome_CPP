#include <iostream> // queens on levels and then nCr
#include <vector>

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
