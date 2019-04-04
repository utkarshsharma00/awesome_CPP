#include <iostream>
#include <string>
using namespace std;

void combbydiv(int lastqueenplacedinwhichbox, int current_queen, string as_of_now, int total_queen, int total_boxes)
{
    if (current_queen > total_queen)
    {
        cout << as_of_now << endl;
        return;
    }

    for (int current_box = lastqueenplacedinwhichbox + 1; current_box < total_boxes; current_box++)
    {
        combbydiv(current_box, current_queen + 1, 'q' + to_string(current_queen) + 'b' + to_string(current_box) + as_of_now, total_queen, total_boxes); // we pass currentbox as a parameter to lastqueen placed because we have to go for the next check because the older one has already been checked and theres no need for it to be checked again. Also currentbox = lastqueenin...
    }
}
int main(int argc, char **argv)
{
    combbydiv(-1, 0, "", 2, 4);
}