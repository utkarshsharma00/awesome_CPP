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
    Node *root = NULL;
    vector<Node *> newlist;
    for (int i = 0; i < datalist.size(); i++)
    {
        if (datalist[i] == -1)
        {
            newlist.pop_back();
        }
        else
        {
            Node *newnode = new Node(datalist[i]);
            if (newlist.size() == 0)
            {
                root = newnode;
                // cout << "oka1";
            }
            else
            {
                //cout << "ok0";
                Node *top_of_stack = newlist.back();
                if (top_of_stack->left == NULL)
                {
                    top_of_stack->left = newnode;
                    // cout << "oka2";
                }
    }
    //yet to be written
}

Node *constructgood1(vector<int> &preorder, vector<int> &inorder, int preoLow, int preoHigh, int inoLow, int inoHigh) //ino means inorder and preo means preorder
{
    //yet to be written
}

Node *constructgood2(vector<int> &postorder, vector<int> &inorder, int postoLow, int postoHigh, int inoLow, int inoHigh)
{
    //yet to be written
}
