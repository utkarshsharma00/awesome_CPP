#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int num;
    cout << "Enter the number of rows upto which you wish to print the pattern\n";
    cin >> num;

    for (int rows = 0; rows < num; rows++)
    {
        int nck = 1; //nck is simply Binomial Coefficient with n and k
        for (int columns = 0; columns <= rows; columns++) 
        {
            cout << nck << "\t";
            nck = (nck * (rows - columns)) / (columns + 1); //calculating 5C1 from 5C0, calculating 5C2 from 5C1 and so on...
        }
        cout << "\n";
    }
}