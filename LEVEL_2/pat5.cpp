#include<iostream>//hollow diamond
using namespace std;

int main(int argc, char **argv)
{
    int num;
    cout << "Enter num";
    cin >> num;
    int stars = num/2 + 1;
    int spaces = 1;

    for (int r = 1; r <= num; r++) // r means rows
    {
        for (int i = 1; i <= stars; i++) // i means cols
        {
            cout << "*";
        }
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
            stars--; //my mistake was that i decremented the stars by 2 
            spaces+=2;
        }
        else
        {
            stars++; //my mistake was that i incremented the stars by 2 
            spaces-=2;
        }
        cout<<endl;
    } 
}

//r
