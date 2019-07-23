#include <queue>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    vector<vector<int>> lists{{2, 5, 9, 18, 20, 25},
                              {3, 7, 8, 15, 22},
                              {0, 4, 6, 12},
                              {1, 10, 16, 21, 28}};
    mergeKsortedLists(lists);
}
