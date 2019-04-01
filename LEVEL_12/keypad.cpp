#include <iostream>
#include <vector>
#include <string>

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

vector<string> keypad(string s)
{
    if (s.size() == 0) //this is basically the code for base case
    {
        vector<string> br;
        br.push_back("");
        return br;
    }
    char ch = s[0];                                           // 6
    string rest_of_string = s.substr(1);                      // 82  // substr is a function in string header file
    vector<string> recursive_string = keypad(rest_of_string); // wd xd we xe wf xf
    vector<string> my_string;

    string code = codes[ch - '0'];                    //pqrs - Reason -> char '0' is subtarcted because its ASCII is 48 and this helps us to give the number of code that we have to play with for example 54-48 = 6 which gives pqrs as above in the codes array
    for (int i = 0; i < recursive_string.size(); i++) // wd xd we xe wf xf
    {
        for (int j = 0; j < code.size(); j++) //pqrs
        {
            my_string.push_back(code[j] + recursive_string[i]);
        }
    }

    return my_string;
}

int main(int argc, char **argv)
{
    string s = "682";
    vector<string> words = keypad(s);
    int counter = 0;
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
        counter++;
    }
    cout << counter << endl;
}