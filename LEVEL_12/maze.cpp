#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> gmp(int current_row, int current_col, int destination_row, int destination_col)
{
    vector<string> horizontal_paths;
    vector<string> vertical_paths;

    if (current_row == destination_row && current_col == destination_col)
    {
        vector<string> bpaths; // this is positive base case
        bpaths.push_back("");
        return bpaths;
    }
    /*if (current_row > destination_row || current_col > destination_col) // this is elegant , this is negative base case
    {
        vector<string> bpaths; // by doing this negative base case we dont need the  ifs down below and can call directly
        // bpaths.push_back("");
        return bpaths;
    }*/

    vector<string> my_paths;

    if (current_col < destination_col)
    {
        vector<string> horizontal_paths = gmp(current_row, current_col + 1, destination_row, destination_col);

        for (int i = 0; i < horizontal_paths.size(); i++)
        {
            my_paths.push_back('h' + horizontal_paths[i]);
        }
    }
    if (current_row < destination_row)
    {
        vector<string> vertical_paths = gmp(current_row + 1, current_col, destination_row, destination_col);

        for (int i = 0; i < vertical_paths.size(); i++)
        {
            my_paths.push_back('v' + vertical_paths[i]);
        }
    }

    return my_paths;
}

int main(int argc, char **argv)
{
    vector<string> paths = gmp(0, 0, 2, 2);
    cout << paths.size();
    for (int i = 0; i < paths.size(); i++)
    {
        cout << paths[i] << endl;
    }
}