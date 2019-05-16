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

Node *construct(vector<int> &datalist)
{
  //yet to be written 
}

void display(Node *root)
{
  //yet to be written 
}
