#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>

using namespace std;

class Interval
{
public:
    int start;
    int end;
    
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
    
    //* Operator Overloading!
    bool operator<(const Interval &O) const //*this const is for 'this'
    {
        return this->start < O.start;
    }
};

void stack_demo()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    while (st.size() > 0)
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << endl;
}
