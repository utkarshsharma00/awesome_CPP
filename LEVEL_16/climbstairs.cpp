#include <iostream>
#include <vector>
using namespace std;

void printstairs(int no_of_stairs, string as_of_now)
{
    static int counter = 0;
    if (no_of_stairs == 0)
    {
        cout << as_of_now << endl;
        counter++;
        cout << counter;
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
    printstairs(7, "");
    int n = 7;
    vector<int> ques(n + 1, 0);
    cout << printstairsMemoisation(7, ques);

    //vector<int> jumpSize{0, 2, 3, 1, 0, 2, 0, 2, 4};
    //cout << climbstairs2(jumpSize) << endl;
}
