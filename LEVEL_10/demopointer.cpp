#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int i = 10;
    int *p = &i; //remove the ampersand from here and understand the error that comes is invalid coversion from int to int
    int **q = &p;
    cout << p << endl;
    cout << *q << endl;
    cout << **q << endl;
    cout << *&*q << endl; //* and & get cancelled because they are just opposite of each other.
}