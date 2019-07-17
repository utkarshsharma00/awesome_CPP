#include <iostream>
#include <vector>
using namespace std;

int stepsknown(vector<int> &jumpSize) //new technique which is known as Tabulation
{
    vector<int> strg(jumpSize.size(), 0); //strg means storage
    strg[0] = 1;
    for (int source = 1; source < jumpSize.size(); source++)
    {
        for (int js = 1; js <= jumpSize[source]; js++) //js means jumpsize
        {
            int intermediate = source - js;
            if (intermediate >= 0)
            {
                strg[source] += strg[intermediate];
            }
            else
            {
                break;
            }
        }
    }

    return strg[strg.size() - 1];

}

int main()
{
    vector<int> jumpSize{0, 2, 3, 1, 0, 2, 0, 2, 4};
    cout << stepsknown(jumpSize) << endl;
}
