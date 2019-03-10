#include <iostream> //cross pattern
using namespace std;

int main(int argc, char **argv)
{
    int num; //this is basically number of rows upto which you wish to print the pattern
    cout << "Enter the value of num\n";
    cin >> num;

    for (int rows = 0; rows < num; rows++)
    {
        for (int columns = 0; columns < num; columns++) // so as to make it a square looking pattern
        {
            if (rows == columns || (rows + columns) == num - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
