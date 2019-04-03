#include <iostream>
#include <string>
#include <vector>
using namespace std;

void floodfill(int current_row, int current_col, int destination_row, int destination_col, vector<vector<int>>&arr, string paths_so_far)
{
    if (current_row == current_col && destination_row == destination_col)
    {
        cout << paths_so_far;
        return;
    }
    if (current_row > destination_row || current_col > destination_col) // this is that case when if we break the wall then we return without printing
    {
        return;
    }

    bool already_visited = true;
    if (current_col + 1 <= destination_col && arr[current_row][current_col + 1] == 0)
    {
        floodfill(current_row, current_col + 1, destination_row, destination_col, arr, 'r' + paths_so_far); // r stands for right
        already_visited = true;
    }
    else
    {
        already_visited = false;
    }

    if (current_row + 1 <= destination_row && arr[current_row + 1][current_col] == 0)
    {
        floodfill(current_row + 1, current_col, destination_row, destination_col, arr, 'd' + paths_so_far); // d stands for down
        already_visited = true;
    }
    else
    {
        already_visited = false;
    }
    if (current_col - 1 >= 0 && arr[current_row][current_col - 1])
    {
        floodfill(current_row, current_col - 1, destination_row, destination_col, arr, 'l' + paths_so_far); // l stands for left
        already_visited = true;
    }
    else
    {
        already_visited = false;
    }
    if (current_row - 1 >= 0 && arr[current_row - 1][current_col])
    {
        floodfill(current_row - 1, current_col, destination_row, destination_col, arr, 't' + paths_so_far); //t stands for top
        already_visited = true;
    }
    else
    {
        already_visited = false;
    }
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
