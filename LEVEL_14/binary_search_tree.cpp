#include <iostream>
#include <vector>
#include <algorithm> //for max() function
#include <climits>

using namespace std;

class Node
{
  public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *construct(vector<int> &datalist, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
  
    int mid = (start + end) / 2;
    Node *root = new Node(datalist[mid]);
    root->left = construct(datalist, start, mid - 1);
    root->right = construct(datalist, mid + 1, end);

    return root;
}

int Min(Node *root)
{
    //yet to be written
}

int Max(Node *root)
{
    //yet to be written
}

void display(Node *root)
{
    //yet to be written
}

int main(int argc, char **argv)
{
    //yet to be written
}
