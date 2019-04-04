#include <iostream>
#include <string>

using namespace std;
void combinations(int queens_placed_so_far, int current_box, string as_of_now, int total_queen, int total_boxes)
{
    if (current_box == total_boxes)
    {
        if (total_queen == queens_placed_so_far)
        {
            cout << as_of_now << endl;
        }
        return;
    }

    combinations(queens_placed_so_far + 1, current_box + 1, 'q' + to_string(queens_placed_so_far) + 'b' + to_string(current_box) + as_of_now, total_queen, total_boxes); //yes call
    combinations(queens_placed_so_far, current_box + 1, as_of_now, total_queen, total_boxes);
}
int main(int argc, char **argv)
{
    combinations(0, 0, "", 2, 4);
}
