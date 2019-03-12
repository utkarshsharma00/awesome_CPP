#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int num;
    cout << "Enter the num\n";
    cin >> num;

    for (int rows = 1; rows <= num; rows++)
    {
        for (int cols = 1; cols <= rows; cols++)
        {
            cout << cols;
        }
        cout << "\n";
    }
}
