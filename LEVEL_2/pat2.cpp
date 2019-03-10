#include <iostream>//fibnoacci-pattern
using namespace std;

int main(int argc, char **argv)
{
    int num;
    cout << "Enter the value of the num\n";
    cin >> num;
    int first_term = 0;
    int second_term = 1;

    for (int rows = 1; rows <= num; rows++)
    {
        for (int columns = 1; columns <= rows; columns++)
        {
            cout << first_term << "\t"; // we are printing first term because the question demands it as the pattern is starting from 0
            int sum_term = first_term + second_term;
            first_term = second_term;
            second_term = sum_term;
        }
        cout << "\n";
    }
}
