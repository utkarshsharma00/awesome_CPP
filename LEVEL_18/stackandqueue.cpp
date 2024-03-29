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
    
    for (int i = 1; i < v.size(); i++)
    {
        while (st1.size() > 0 && v[st1.top()] > v[i])
        {
            st1.pop();
        }
        left_bound[i] = st1.size() > 0 ? st1.top() : -1;
        st1.push(i);
    }
    
    vector<int> right_bound(v.size(), 0);
    stack<int> st2;
    st2.push(v.size() - 1);
    right_bound[v.size() - 1] = v.size();
    
    for (int i = v.size() - 2; i >= 0; i--)
    {
        while (st2.size() > 0 && v[st2.top()] > v[i])
        {
            st2.pop();
        }
        right_bound[i] = st2.size() > 0 ? st2.top() : -1;
        st2.push(i);
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        int current_area = (right_bound[i] - left_bound[i] - 1) * v[i];
        if (current_area > max_area)
        {
            max_area = current_area;
        }
    }
    return max_area;
}

vector<int> *sliding_window_max(vector<int> &v, int window_size)
{
    vector<int> nge(v.size(), 0); //* nge means next_greater_element
    stack<int> st;
    nge[v.size() - 1] = v.size();
    st.push(v.size() - 1);
    
    for (int i = v.size() - 2; i >= 0; i--)
    {
        while (st.size() > 0 && v[st.top()] < v[i])
        {
            st.pop();
        }

        nge[i] = st.size() == 0 ? v.size() : st.top();
        st.push(i);
    }
    
    vector<int> *result = new vector<int>(v.size() - window_size + 1);
    int j = 0;
    for (int i = 0; i < v.size() - window_size + 1; i++) //* i is traversing for windows that is first window start point, then second window start point and so on...
    {
        if (j < i)
        {
            j = i;
        }

        while (nge[j] < i + window_size)
        {
            j = nge[j];
        }
        (*result)[i] = j;
    }
    return result;
}

bool duplicate_brackets(string Input)
{
    stack<char> st;

    for (int i = 0; i < Input.size(); i++)
    {
        char ch = Input[i];
        if (ch == ')')
        {
            if (st.top() == '(')
            {
                return true;
            }
            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
        else
        {
            st.push(ch);
        }
    }
    
    return false;
}

void celebrity(vector<vector<bool>> &v)
{
    int n = v.size();
    int left = 0;
    int right = n - 1;

    while (left != right)
    {
        if (v[left][right] == 1)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    
    for (int i = 0; i < left; i++)
    {
        if (i != left)
        {
            if (v[i][left] == false || v[left][i] == true)
            {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << left << endl;
}

void overlapping_intervals(vector<int> &starts, vector<int> &ends)
{
    vector<Interval> intervals;

    for (int i = 0; i < starts.size(); i++)
    {
        Interval interval2(starts[i], ends[i]);
        intervals.push_back(interval2);
    }
    
    sort(intervals.begin(), intervals.end());

    stack<Interval> st;
    st.push(intervals[0]);
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i].start <= st.top().end)
        {
            st.top().end = max(st.top().end, intervals[i].end);
        }
        else
        {
            st.push(intervals[i]);
        }
    }
    
    while (st.size() > 0)
    {
        cout << st.top().start << "-" << st.top().end << endl;
        st.pop();
    }
}

void stock_span(vector<int> &v)
{
    stack<int> st;
    st.push(0);
    
    vector<int> result(v.size(), 0);
    result[0] = 0;

    for (int i = 0; i < v.size(); i++)
    {
        while (st.size() > 0 && v[st.top()] < v[i])
        {
            st.pop();
        }

        st.push(i);
    }
}

int get_priority(char Operator)
{
    int return_value = -1;

    switch (Operator)
    {
    case '^':
        return_value = 3;
        break;
    case '*': //*combining of two cases
    case '/':
        return_value = 2;
        break;
    case '+':
    case '-':
        return_value = 1;
        break;
    default:
        break;
    }

    return return_value;   
}

int get_value(char Operator, int num1, int num2)
{
    int return_value = -1;

    switch (Operator)
    {
    case '^':
        return_value = (int)pow(num1, num2);
        break;
    case '*':
        return_value = num1 * num2;
        break;
    case '/':
        return_value = num1 / num2;
        break;
    case '+':
        return_value = num1 + num2;
        break;
    case '-':
        return_value = num1 - num2;
        break;

    default:
        break;
    }

    return return_value; 
}

void infix_evaluation(string expression)
{
    stack<char> opening_stack;
    stack<int> value_stack;
    
    for (int i = 0; i < expression.size(); i++)
    {
        char ch = expression[i];

        if (ch == '(')
        {
            opening_stack.push(ch);
        }
        else if (ch >= '0' && ch <= '9')
        {
            value_stack.push(ch - '0');
        }
        else
        {
            while (!(opening_stack.size() == 0 || opening_stack.top() == '(' || get_priority(opening_stack.top()) < get_priority(ch)))
            {
                char Operator = opening_stack.top();
                opening_stack.pop();
                int num2 = value_stack.top();
                value_stack.pop();
                int num1 = value_stack.top();
                value_stack.pop();

                value_stack.push(get_value(Operator, num1, num2));
            }
            opening_stack.push(ch);
        }
    }   
    
    cout << value_stack.top();
}

string infix_to_postfix(string expression)
{
    string postfix;
    stack<char> opening_stack;
    
   for (int i = 0; i < expression.size(); i++)
    {
        char ch = expression[i];

        if (ch == '(')
        {
            opening_stack.push(ch);
        }
        else if (ch == ')')
        {
            while (opening_stack.top() != '(')
            {
                char Operator = opening_stack.top();
                opening_stack.pop();
                postfix += Operator;
            }
            opening_stack.pop();
        }
        else if (ch >= '0' && ch <= '9')
        {
            postfix += ch;
        }
        else
        {
            while (opening_stack.size() > 0 && opening_stack.top() != '(' && get_priority(opening_stack.top() >= get_priority(ch)))
            {
                char Operator = opening_stack.top();
                opening_stack.pop();
                postfix += Operator;
            }
            opening_stack.push(ch);
        }
   }   
   
   while (opening_stack.size() > 0)
    {
        char Operator = opening_stack.top();
        opening_stack.pop();
        postfix += Operator;
    }
    return postfix;
}

void post123(string post_exp)
{
    //TODO Postfix Evaluation
    stack<int> es; //evaluation_stack
    
    for (int i = 0; i < post_exp.length(); i++)
    {
        char ch = post_exp[i];
        if (ch >= '0' && ch <= '9')
        {
            es.push(ch - '0');
        }
        else
        {
            int val2 = es.top();
            es.pop();
            int val1 = es.top();
            es.pop();
            es.push(get_value(ch, val1, val2));
        }
    }
    
    cout << es.top() << endl;

    //TODO Post to Infix
    stack<string> is;
    for (int i = 0; i < post_exp.length(); i++)
    {
        char ch = post_exp[i];
        if (ch >= '0' && ch <= '9')
        {
            string s = string() + ch;
            is.push(s);
        }
        else
        {
            // string s = string() + ch;
            string s2 = is.top();
            is.pop();
            string s1 = is.top();
            is.pop();
            is.push("(" + s1 + ch + s2 + ")");
        }
    }
    
    cout << is.top() << endl;
    
    //TODO Post to Pre
    stack<string> pres;
    for (int i = 0; i < post_exp.length(); i++)
    {
        char ch = post_exp[i];
        if (ch >= '0' && ch <= '9')
        {
            string s = string() + ch;
            pres.push(s);
        }
        else
        {
            string pval2 = pres.top();
            pres.pop();
            string pval1 = pres.top();
            pres.pop();
            string pval = ch + pval1 + pval2;
            pres.push(pval);
        }
    }    
    
    cout << pres.top();
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
    
    cout << "Celebrity" << endl;
    celebrity(v3);
    cout << "\nIntervals\n";
    vector<int> starts = {22, 17, 19, 2, 6, 12, 3};
    vector<int> ends = {26, 20, 23, 4, 9, 15, 7};
    overlapping_intervals(starts, ends);
    cout << endl;
    vector<int> v4 = {};
    cout << "Stock Span\n";
    stock_span(v4);
    
    cout << "Infix Eval\n";
    string s1 = "8+2/3+2^1*(1+3)";
    infix_evaluation(s1);
    cout << endl;
    cout << "\nInfix to Postfix\n";
    cout << infix_to_postfix(s1);
    cout << endl;
    cout << "\nPost123\n";
    post123("24/32^-");
    cout << endl;
}
