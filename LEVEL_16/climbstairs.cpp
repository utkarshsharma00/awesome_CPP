#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    //printstairs(7, "");
    // int n = 7;
    // vector<int> ques(n + 1, 0);
    // cout << printstairsMemoisation(7, ques);

    vector<int> jumpSize{0, 2, 3, 1, 0, 2, 0, 2, 4};
    cout << climbstairs2(jumpSize) << endl;
}
