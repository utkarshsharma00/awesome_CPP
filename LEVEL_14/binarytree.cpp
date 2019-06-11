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
                else
                {
                    top_of_stack->right = newnode;
                }
                // cout << "oka3";
            }
            newlist.push_back(newnode);
        }
    }
    return (root);
}

Node *constructgood1(vector<int> &preorder, vector<int> &inorder, int preoLow, int preoHigh, int inoLow, int inoHigh) //ino means inorder and preo means preorder
{
    if (preoLow > preoHigh || inoLow > inoHigh)
    {
        return NULL;
    }
    
    Node *root = new Node(preorder[preoLow]);
    int foundAt = -1;
    for (int i = inoLow; i <= inoHigh; i++)
    {
        if (inorder[i] == preorder[preoLow])
        {
            foundAt = i;
            break;
        }
    }
    //yet to be written
}

Node *constructgood2(vector<int> &postorder, vector<int> &inorder, int postoLow, int postoHigh, int inoLow, int inoHigh)
{
    //yet to be written
}

int maxintree(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    
    return max(max(maxintree(root->left), maxintree(root->right)), root->data);
}

int height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    
     return max(height(root->left), height(root->right)) + 1;
}

bool Find(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    
    bool find_in_left_child = Find(root->left, data);
    if (find_in_left_child == true)
    {
        return true;
    }

    bool find_in_right_child = Find(root->right, data);
    if (find_in_right_child == true)
    {
        return true;
    }

    return false;
}

vector<int> *Node2RootPath(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *base_result = new vector<int>();
        base_result->push_back(root->data);
        return base_result;
    }
    vector<int> *node2leftpath = Node2RootPath(root->left, data);
    if (node2leftpath != NULL)
    {
        node2leftpath->push_back(root->data);
        return node2leftpath;
    }
    vector<int> *node2rightpath = Node2RootPath(root->right, data);
    {
        if (node2rightpath != NULL)
        {
            node2rightpath->push_back(root->data);
            return node2rightpath;
        }
    }
    return NULL;
}

vector<Node *> *Node2RootPathForKfar(Node *root, int data)
{
    //yet to be written
}

void kdown(Node *root, int key)
{
    if(root == NULL)
    {
        return;
    }
    if (key == 0)
    {
        cout << root->data << endl;
        return;
    }

    kdown(root->left, key - 1);
    kdown(root->right, key - 1);
}

void kdown2(Node *root, Node *prohibiter, int key) //* will be used in kfar()
{
    if (root == NULL || root == prohibiter)
    {
        return;
    }
    if (key == 0)
    {
        cout << root->data << endl;
        return;
    }
    kdown2(root->left, prohibiter, key - 1);
    kdown2(root->right, prohibiter, key - 1);
}

void kfar(Node *root, int data, int key)
{
    vector<Node *> *Node2RootPath = Node2RootPathForKfar(root, data);
    for (int i = 0; i <= key && i < Node2RootPath->size(); i++)
    {
        kdown2(Node2RootPath->at(i), i == 0 ? NULL : Node2RootPath->at(i - 1), key - i);
    }
}

display(Node *root)
{
    if (root->left != NULL && root->right != NULL)
    {
        cout << root->left->data << "<-" << root->data << "->" << root->right->data << endl;
        display(root->left);
        display(root->right);
    }
    else if (root->left != NULL)
    {
        cout << root->left->data << "<-" << root->data << "." << endl;
        display(root->left);
    }
    else if (root->right != NULL)
    {
        cout << "." << root->data << "->" << root->right->data << endl;
        display(root->right);
    }
    else
    {
        cout << "." << root->data << "." << endl;
    }
}

int main(int argc, char **argv)
{
    vector<int> list{
        50, 25, 12, -1, 37, 30, -1, 40, -1, -1, -1, 75, 62, 60, -1, 70, -1, -1, 87, -1, -1, -1};
    Node *root = construct(list);
    display(root);
    cout << endl;
    cout << "Height is" << endl;
    cout << height(root);
    cout << endl;
    cout << "Max in tree is" << endl;
    cout << maxintree(root);
    cout << endl;
    cout << "Find in tree 0/1 ?" << endl;
    cout << Find(root, 25);
    cout << endl;
    cout << "K_down" << endl;
    kdown(root, 3);
    
    //*These vectors below have been created for generating tress from (preorder,inorder) and (postorder,inorder)
    vector<int> preorder{
        50, 25, 12, 37, 40, 75, 62, 87};

    vector<int> inorder{
        12, 25, 37, 40, 50, 62, 75, 87};

    vector<int> postorder{
        12, 40, 37, 25, 62, 87, 75, 50};
}
