#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int rows;
    cout << "Enter the no_of_Rows upto which you wish to print the pattern\n";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
}