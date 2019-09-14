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
    if (root->left != NULL)
    {
        return Min(root->left);
    }
    else
    {
        return root->data;
    }
}

int Max(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

bool find(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    //yet to be written
}

void display(Node *root)
{
    if (root->left != NULL && root->right != NULL)
    {
        cout << root->left->data << "<-" << root->data << "->" << root->right->data << endl;
        display(root->left);
        display(root->right);
    }
  //yet to be written
}

int main(int argc, char **argv)
{
    vector<int> datalist{12, 25, 37, 50, 62, 75, 87};
    Node *root = construct(datalist, 0, datalist.size() - 1);
    //yet to be written
}
