#include <iostream>
#include <vector>
#include <climits>
#include <list>
using namespace std;

class Node
{
  public:
    int data;
    vector<Node *> children;

    Node(int data)
    {
        this->data = data;
    }
};
