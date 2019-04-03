#include <iostream>
#include <string>
using namespace std;

void printpermutations(int current_queen, bool boxes[], string as_of_now, int total_queens, int total_boxes)
{

    if (current_queen > total_queens)
    {
        cout << as_of_now << endl;
        return;
    }

    for (int b = 0; b < total_boxes; b++)
    {

        if (boxes[b] == false) //queen is in the box
        {
            boxes[b] = true;
            printpermutations(current_queen + 1, boxes, 'q' + to_string(current_queen) + 'b' + to_string(b) + as_of_now, total_queens, total_boxes);
            boxes[b] = false; //making it false in order to make it empty for the other queens
        }
    }
}

int main(int argc, char **argv)
{
    bool boxes[5];
    printpermutations(1, boxes, "", 2, 5);
}