#include <iostream> //! think in terms of Kadane's algo.
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> oil{6, 4, 8, 2, 3, 3, 1, 7, 2};
    vector<int> dist{5, 5, 2, 4, 4, 6, 2, 7, 1};
    petrolpump(oil, dist);
}
