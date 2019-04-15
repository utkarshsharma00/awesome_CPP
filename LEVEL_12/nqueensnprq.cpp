#include <iostream> //queens on levels and nPr
#include <vector>
using namespace std;

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
