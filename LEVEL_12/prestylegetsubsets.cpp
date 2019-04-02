#include <iostream>
using namespace std;

void printstylegss(string question, string as_of_now)
{
    if (question.length() == 0)
    {
        cout << as_of_now << endl;
        return;
    }
    char ch = question[0];
    string rest_of_question = question.substr(1);

    printstylegss(rest_of_question, as_of_now + ch);
    printstylegss(rest_of_question, as_of_now + '-');
}
int main(int argc, char **argv)
{
    printstylegss("abc", "");
}
