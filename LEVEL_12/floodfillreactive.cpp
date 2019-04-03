#include <iostream>
#include <vector>
using namespace std;

void floodfill(int current_row, int current_col, int destination_row, int destination_col, vector<vector<int>> &arr, string paths_so_far)
{ //passing of this ampersand in array is very important otherwise it will lead to Deep Copy of the contents of the vector which is very costly in terms of memeory
    if (current_row == destination_row && current_col == destination_col)
    {
        cout << paths_so_far << endl;
        return;
    }

    if (current_row < 0 || current_col < 0 || current_row > destination_row || current_col > destination_col || arr[current_row][current_col] == 1 || arr[current_row][current_col] == 2) // where 1 stands for obstacles and 2 for marking it as visited
    {
        return;
    }

    arr[current_row][current_col] = 2; // means marking it as visited
    floodfill(current_row, current_col + 1, destination_row, destination_col, arr, 'r' + paths_so_far);
    floodfill(current_row, current_col - 1, destination_row, destination_col, arr, 'l' + paths_so_far); // l stands for left
    floodfill(current_row - 1, current_col, destination_row, destination_col, arr, 't' + paths_so_far); //t stands for top
    floodfill(current_row + 1, current_col, destination_row, destination_col, arr, 'd' + paths_so_far); // d stands for down
    arr[current_row][current_col] = 0;                                                                  //for unmarking
}

int main(int argc, char **argv)
{
    vector<vector<int>> arr = {
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0}};

    floodfill(0, 0, 5, 5, arr, "");
}
