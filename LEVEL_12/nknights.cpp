#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    vector<vector<bool>> board{
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}

    };
    nknights(board, 0, 0, "");
}
