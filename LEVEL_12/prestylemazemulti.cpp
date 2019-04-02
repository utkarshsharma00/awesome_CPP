#include <iostream>
using namespace std;

void prestylemazes(int current_row, int current_col, int destination_row, int destination_col, string as_of_now)
{
    if (current_row == destination_row && current_col == destination_col)
    {
        cout << as_of_now << endl;
        return;
    }
    if (current_row > destination_row || current_col > destination_col) // this is that case when if we break the wall then we return without printing
    {

        return;
    }

    prestylemazes(current_row, current_col + 1, destination_row, destination_col, 'h' + as_of_now);
    prestylemazes(current_row + 1, current_col, destination_row, destination_col, 'v' + as_of_now);
    prestylemazes(current_row + 1, current_col + 1, destination_row, destination_col, 'd' + as_of_now);
}

int main(int argc, char **argv)
{
    prestylemazes(0, 0, 2, 2, "");
}