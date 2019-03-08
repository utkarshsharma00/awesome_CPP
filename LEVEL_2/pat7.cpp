#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int num;
    cout << "Enter the num\n";
    cin >> num;

    int stars = 1;
    int spaces = num / 2;
    int variable = 1;
    int i;
    for (int r = 1; r <= num; r++)
    {
        for (int i = 1; i <= spaces; i++)
        {
            cout << " ";
        }

        int mvar = variable;
        for (int i = 1; i <= stars; i++)
        {
            cout << mvar;
            
            if (i <= stars / 2)
            {
                mvar++;
            }
            else
            {   
                mvar--;
            }
        }

        if (r <= num / 2)
        {
            stars += 2;
            spaces--;
            variable++;
        }
        else
        {
            stars -= 2;
            spaces++;
            variable--;
        }

        cout << endl;
    }
}