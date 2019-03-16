#include <iostream>
#include <climits>
using namespace std;
// character against negative ascii
int main(int argc, char **argv)
{
    /*char ch = 255; 
    cout<<CHAR_MIN;
    cout<<CHAR_MAX;*/
    char c;
    cout << "Enter a character of your choice\n";
    cin >> c;

    if (c >= 'a' && c <= 'z')
    {
        cout << "Lower case";
        char uc = 'A' + (c - 'a');
        cout << uc << endl;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        cout << "Upper case";
        char lc = 'a' + (c - 'A');
        cout << lc << endl;
    }
    else
    {
        cout << "Wrong input\n";
    }
}