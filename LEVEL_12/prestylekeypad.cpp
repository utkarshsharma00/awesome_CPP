#include <iostream>
using namespace std;

string codes[] = {
    ",;",   //0
    "abc",  //1
    "def",  //2
    "ghi",  //3
    "jkl",  //4
    "mno",  //5
    "pqrs", //6
    "tuv",  //7
    "wx",   //8
    "yz"    //9

};

void prestylekpc(string question, string as_of_now)
{
    if (question.length() == 0)
    {
        cout << as_of_now << endl;
        return;
    }
    char ch = question[0];
    string rest_of_question = question.substr(1);

    for (int i = 0; i < codes[ch - '0'].size(); i++)
    {
        prestylekpc(rest_of_question, as_of_now + codes[ch - '0'][i]);
    }
}

int main(int argc, char **argv)
{
    prestylekpc("682", "");
}