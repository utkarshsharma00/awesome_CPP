#include <iostream> //diamond
using namespace std;

int main(int argc, char **argv)
{
    int num;
    cout << "Enter num";
    cin >> num;
    int stars = 1;
    int spaces = num / 2;

    for (int r = 1; r <= num; r++)
    {
        for (int i = 1; i <= spaces; i++)
        {
            cout << " ";
        }
        for (int i = 1; i <= stars; i++)
        {
            cout << "*";
        }
        if (r <= num / 2)
        {
            stars += 2;
            spaces--;
        }
        else
        {
            stars -= 2;
            spaces++;
        }
        cout<<endl;
    } 
}

