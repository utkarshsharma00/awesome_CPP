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

Node *construct(vector<int> &datalist)
{
    //yet to be written
}

Node *constructgood1(vector<int> &preorder, vector<int> &inorder, int preoLow, int preoHigh, int inoLow, int inoHigh) //ino means inorder and preo means preorder
{
    //yet to be written
}
