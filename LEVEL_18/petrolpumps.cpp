#include <iostream> //! think in terms of Kadane's algo.
#include <vector>
using namespace std;

int petrolpump(vector<int> &oil, vector<int> &dist)
{
    int spare = 0;
    int start = 0;
    int end = 0;
    
    while (true)
    {
        if (spare + oil[end] >= dist[end])
        {
            spare = spare + oil[end] - dist[end];
            end = (end + 1) % oil.size();

            if (end == start)
            {
                cout << start << endl;
                break;
            }
        }
    }    
}

int main(int argc, char **argv)
{
    vector<int> oil{6, 4, 8, 2, 3, 3, 1, 7, 2};
    vector<int> dist{5, 5, 2, 4, 4, 6, 2, 7, 1};
    petrolpump(oil, dist);
}
