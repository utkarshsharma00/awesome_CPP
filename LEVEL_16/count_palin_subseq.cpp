#include <iostream> //* In this code we find the answer of the count at the topmost right corner of the printed storage vector
#include <vector>
#include <string>

using namespace std;

int counter = 0;

void count_palindromic_subseq(string s)
{
    vector<vector<int>> storage(s.length(), vector<int>(s.length()));
    for (int gap = 0; gap < s.size(); gap++)
    {
        for (int i = 0, j = i + gap; j < storage.size(); i++, j++)
        {
            if (gap == 0)
            {
                storage[i][j] = 1;
            }
        }   
    }    
}

int main(int argc, char **argv)
{
    count_palindromic_subseq("abgcckyb");
}
