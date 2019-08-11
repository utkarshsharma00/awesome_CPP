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
    
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

void next_greater_elementLtoR(vector<int> &v)
{
    vector<int> result(v.size(), 0);
    stack<int> st;
    
    or (int i = 0; i < v.size(); i++)
    {
        while (st.size() > 0 && v[st.top()] < v[i])
        {
            result[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    
    while (st.size() > 0)
    {
        result[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int largest_area_histogram(vector<int> &v)
{
    int max_area = 0;

    vector<int> left_bound(v.size(), 0);
    stack<int> st1;
    st1.push(0);
    left_bound[0] = -1;
    //yet to be written
}

vector<int> *sliding_window_max(vector<int> &v, int window_size)
{
    vector<int> nge(v.size(), 0); //* nge means next_greater_element
    stack<int> st;
    nge[v.size() - 1] = v.size();
    st.push(v.size() - 1);
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
    
    cout << "Decrease Increase String" << endl;
    decrease_increase_string("ddiddddd");
    vector<int> v{1, 2, 7, 9, 6, 5, 3, 8};
    cout << "Next Greater Element R to L approach\n";
    next_greater_element(v);
    cout << "Next Greater Element L to R approach\n";
    next_greater_elementLtoR(v);
    cout << "Histogram Largest Area\n";
    vector<int> v1 = {6, 2, 5, 4, 5, 1, 6};
    cout << largest_area_histogram(v1) << endl;
    cout << "Sliding Window Max.\n";
    vector<int> v2 = {2, 7, 3, 1, 6, 8, 4, 9, 5, 10};
    vector<int> *arr = sliding_window_max(v2, 5);
    for (int i = 0; i < arr->size(); i++)
    {
        cout << (*arr)[i];
    }
    cout << "\n";
    cout << "Duplicate Brackets Case when duplicate are present\n";
    cout << duplicate_brackets("((a+b)+((c+d))") << endl;
    cout << "Duplicate Brackets Case when duplicate are NOT present\n";
    cout << duplicate_brackets("((a+b)+(c+d)") << endl;
    vector<vector<bool>> v3 = {{0, 0, 1, 0, 1, 1},
                               {1, 0, 1, 1, 1, 1},
                               {1, 0, 0, 1, 1, 0},
                               {0, 0, 0, 0, 1, 0},
                               {0, 0, 0, 0, 0, 0},
                               {1, 0, 1, 1, 1, 0}};
}
