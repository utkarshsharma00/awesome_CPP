#include <iostream> //do put an image of the Euler Tree if possible
#include <string>

using namespace std;

void perma(string ques, string ans)
{
    if (ques.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = ques[0];
    string ros = ques.substr(1);
    for (int i = 0; i < ans.length() + 1; i++)
    {
        string left = ans.substr(0, i);
        string right = ans.substr(i);
        perma(ros, left + ch + right);
    }
}
int main(int argc, char **argv)
{
    perma("abc", "");
}
