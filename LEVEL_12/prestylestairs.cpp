#include <iostream>
using namespace std;

void printstairs(int no_of_stairs, string as_of_now)
{

    if (no_of_stairs == 0)
    {
        cout << as_of_now << endl; //when I coded i missed the base case. so remember it
        return;
    }

    for (int steps = 1; steps <= 3; steps++)
    {
        if (no_of_stairs - steps >= 0)
        {
            printstairs(no_of_stairs - steps, as_of_now + to_string(steps));
        }
    }
}
int main(int argc, char **argv)
{
    printstairs(4, "");
}