#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int number;
    cout << "Enter the number" << endl;
    cin >> number;
    int rotation;
    cout << "Enter a rotation factor" << endl;
    cin >> rotation;

    int no_ofdigits = 0;
    int safe = number;

    while (number != 0)
    {
        no_ofdigits++;
        number = number / 10;
    }

    number = safe;
    rotation = rotation%no_ofdigits; //for handling all the cases
    rotation = (rotation < 0) ? rotation + no_ofdigits : rotation; // for handling all the conditions of positive and negative rotations

    int multiplier = 1;
    int divisor = 1;
    for (int i = 1; i <= no_ofdigits; i++)
    {
        if (i <= rotation)
        {
            divisor = divisor * 10;
        }
        else
        {
            multiplier = multiplier * 10;
        }
    }

    int remainder = number%divisor;
    int foo = number/divisor;
    int answer = (remainder*multiplier) + foo;
    cout<<answer;
}