#include <iostream>
#include <string>

using namespace std;

void permq(string ques, string ans)
{
    if (ques.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < ques.size(); i++)
    {
        char ch = ques[i];
        string left = ques.substr(0, i);
        string right = ques.substr(i + 1);
        permq(left + right, ans + ch);
    }
}

int main(int argc, char **argv)
{
    permq("abc", "");
}
