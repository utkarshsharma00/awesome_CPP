#include <iostream> //erratic code output,its output soleley depends on the compiler design
using namespace std;

int *fun();
void static_fun();
void normal_fun();

int main(int argc, char **argv)
{
    int i = 10;
    int *p = fun();
    cout << pair << endl;
    cout << *pair << endl;

    for (int i = 0; i < 5; i++)
    {
        normal_fun(); // prints 21, 5 times
        static_fun(); // prints 21 , 22 , 23 , 24 , 25
    }
}

int *fun()
{
    //static int x = 10;
    int x = 10;
    return &x; //never return the address of local variable, to solve this make this global or make x static as in the above comment
}

void normal_fun()
{
    int y = 20;
    y++;
    cout << y;
}

void static_fun()
{
    static int y = 20;
    y++;
    cout << y << endl;
}