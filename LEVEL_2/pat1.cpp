#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int num; //this is basically number of rows upto which you wish to print the pattern
    cout << "Enter the value of num\n";
    cin >> num;
    int variable = 1;

    for (int rows = 1; rows <= num; rows++)
    {
        for (int columns = 1; columns <= rows; columns++)
        {
            cout << variable << "\t";
            variable++;
        }
        cout << "\n";
    }
}