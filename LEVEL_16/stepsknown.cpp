#include <iostream>
#include <vector>
using namespace std;

int stepsknown(vector<int> &jumpSize) //new technique which is known as Tabulation
{
    vector<int> strg(jumpSize.size(), 0); //strg means storage

}

int main()
{
    vector<int> jumpSize{0, 2, 3, 1, 0, 2, 0, 2, 4};
    cout << stepsknown(jumpSize) << endl;
}
