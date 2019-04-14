#include <iostream>
#include <string>

using namespace std;

void permqd(string ques, string ans)
{
    if (ques.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    int bm = 0;
    for (int i = 0; i < ques.size(); i++)
    {
        char ch = ques[i];
        string left = ques.substr(0, i);
        string right = ques.substr(i + 1);
        if ((bm & (1 << (ch - 97))) == 0)
        {
            bm = bm | (1 << (ch - 97));
            permqd(left + right, ans + ch);
        }
    }
}

int main(int argc, char **argv)
{
    permqd("baba", "");
}
