#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

int main(int argc, char **argv)
{
    vector<int> one{2, 1, 5, 1, 3, 2, 1};
    vector<int> two{4, 5, 2, 1, 2, 1, 2};
    print_common_elements1(one, two);
    cout << endl;
    print_common_elements2(one, two);
}
