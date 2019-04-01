#include <iostream> // string indexing is same as array that is start from 0
#include <vector>
#include <string>

using namespace std;

vector<string> gss(string s)
{
    if (s.size() == 0) //this is basically the code for base case
    {
        vector<string> br;
        br.push_back("");
        return br;
    }
    char ch = s[0];                                        //a
    string rest_of_string = s.substr(1);                   // bc  // substr is a function in string header file
    vector<string> recursive_string = gss(rest_of_string); // this reads the string from 1st char to the end of string
    vector<string> my_string;
    for (int i = 0; i < recursive_string.size(); i++)
    {
        my_string.push_back('-' + recursive_string[i]);
        my_string.push_back(ch + recursive_string[i]);
    }

    return my_string;
}

int main()
{
    vector<string> vec = gss("abcdef");
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
}
