#include <iostream> //* The total number of 1's in the storage vector is our desired answer
#include <vector>
#include <string>

using namespace std;

void count_palin_substring(string s)
{
    vector<vector<bool>> storage(s.length(), vector<bool>(s.length()));
}

int main()
{
    count_palin_substring("abccbc");
}
  
