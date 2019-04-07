#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canPlaceTheWordH(vector<vector<char>> &board, int i, int j, string word)
{
    if (j + word.size() > board.size())
    {
        return false;
    }
    else if (j > 0 && board[i][j - 1] != '+')
    {
        return false;
    }
    else if (j + word.size() < board.size() && board[i][j + word.size()] != '+')
    {
        return false;
    }
    else
    {
        for (int ii = 0; ii < word.size(); ii++)
        {
            if (board[i][j + ii] != '-' && board[i][j + ii] != word[ii])
            {
                return false;
            }
        }

        return true;
    }
}

bool PlaceWordH(vector<vector<char>> &board, int i, int j, string word, bool check[])
{
    for (int ii = 0; ii < word.size(); ii++)
    {
        check[ii] = board[i][j + ii] == '-';
        board[i][j + ii] = word[ii];
    }
}

bool UnplaceWordH(vector<vector<char>> &board, int i, int j, string word, bool check[])
{
    for (int ii = 0; ii < word.size(); ii++)
    {
        if (check[ii] == true)
        {
            board[i][j + ii] = '-';
        }
    }
}

//create the above functions for vertical direction as well !

int main(int argc, char **argv)
{
    vector<vector<char>> board{
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

    vector<string> words{"AGRA", "NORWAY", "ENGLAND", "GWALIOR"};
    crossword1(board, words, 0);
}
