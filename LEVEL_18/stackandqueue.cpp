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

void decrease_increase_string(string Input)
{
    int val = 1;
    stack<int> st;
    for (int i = 0; i < Input.length(); i++)
    {
        char ch = Input[i];
        st.push(val++);

        if (ch == 'i')
        {
            while (st.size() > 0)
            {
                cout << st.top();
                st.pop();
            }
        }
    }
    
    st.push(val++);
    while (st.size() > 0)
    {
        cout << st.top();
        st.pop();
    }

    cout << endl;
}

void next_greater_element(vector<int> &v) //* Right To Left Thinking/Approach
{
    vector<int> result(v.size(), 0);
    stack<int> st;
    st.push(v[v.size() - 1]);
    result[v.size() - 1] = -1;
    for (int i = v.size() - 2; i >= 0; i--)
    {
        while (st.size() > 0 && v[i] > st.top())
        {
            st.pop();
        }

        result[i] = st.size() > 0 ? st.top() : -1;
        st.push(v[i]);
    }
}

void next_greater_elementLtoR(vector<int> &v)
{
    vector<int> result(v.size(), 0);
    stack<int> st;

    //yet to be written   
}

int largest_area_histogram(vector<int> &v)
{
    //yet to be written
}

vector<int> *sliding_window_max(vector<int> &v, int window_size)
{
    //yet to be written
}

bool duplicate_brackets(string Input)
{
    //yet to be written
}

void celebrity(vector<vector<bool>> &v)
{
    //yet to be written
}

void overlapping_intervals(vector<int> &starts, vector<int> &ends)
{
    //yet to be written
}

int main(int argc, char **argv)
{
    cout << "Stack Demo\n";
    stack_demo();
}
