#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

class Activity
{
public:
    int start_time;
    int end_time;

    Activity(int start_time, int end_time)
    {
        this->start_time = start_time;
        this->end_time = end_time;
    }
    
    //yet to be written
};

void activity_selection(priority_queue<Activity, vector<Activity>, greater<Activity>> &pq)
{
    int counter = 1;
    Activity base = pq.top();
    pq.pop();
    
    //yet to be written
}

int main(int argc, char **argv)
{
    priority_queue<Activity, vector<Activity>, greater<Activity>> pq;

    vector<int> start{3, 0, 1, 8, 5, 5};
    vector<int> end{4, 6, 2, 9, 9, 7};
    
    for (int i = 0; i < start.size(); i++)
    {
        pq.push(Activity(start[i], end[i]));
    }

    activity_selection(pq);
}
