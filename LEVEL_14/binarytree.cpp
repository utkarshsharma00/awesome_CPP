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
    
    int lhs = foundAt - inoLow; //* this gives the no. of nodes on the left sides
    root->left = constructgood1(preorder, inorder, preoLow + 1, preoLow + lhs, inoLow, foundAt - 1);
    root->right = constructgood1(preorder, inorder, preoLow + lhs + 1, preoHigh, foundAt + 1, inoHigh);
    return root;
}

Node *constructgood2(vector<int> &postorder, vector<int> &inorder, int postoLow, int postoHigh, int inoLow, int inoHigh)
{
    if (postoLow > postoHigh || inoLow > inoHigh)
    {
        return NULL;
    }

    Node *root = new Node(postorder[postoHigh]);
    int foundAt = -1;
    for (int i = inoHigh; i >= 0; i--)
    {
        if (inorder[i] == postorder[postoHigh])
        {
            foundAt = i;
            break;
        }
    }
    
    int rhs = inoHigh - (foundAt);
    root->left = constructgood2(postorder, inorder, postoLow, postoHigh - rhs - 1, inoLow, foundAt - 1); //* use a little bit of brains for passing the params, they look difficult but are really easy
    root->right = constructgood2(postorder, inorder, postoHigh - rhs, postoHigh - 1, foundAt + 1, inoHigh);
    return root;
}

Node *constructOnly_From_Pre_and_Post(vector<int> &preorder, vector<int> &postorder, int preoLow, int preoHigh, int postoLow, int postoHigh)
{
    Node *root = new Node(preorder[preoLow]);
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
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<Node *> *base_result = new vector<Node *>();
        base_result->push_back(root);
        return base_result;
    }
    
    vector<Node *> *node2leftpath = Node2RootPathForKfar(root->left, data);
    if (node2leftpath != NULL)
    {
        node2leftpath->push_back(root);
        return node2leftpath;
    }
    vector<Node *> *node2rightpath = Node2RootPathForKfar(root->right, data);
    {
        if (node2rightpath != NULL)
        {
            node2rightpath->push_back(root);
            return node2rightpath;
        }
    }
    return NULL;
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

Node *removeLeavesTheBestWay(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    root->left = removeLeavesTheBestWay(root->left);
    root->right = removeLeavesTheBestWay(root->right);
    return root;
}

void RootToLeavePathInRange(Node *root, int low, int high, vector<int> &path, int sum)
{
    if (root == NULL)
    {
        return;
    }
    
    if (root->left == NULL && root->right == NULL)
    {
        path.push_back(root->data);
        sum = sum + root->data;
        if (sum >= low && sum <= high)
        {
            for (int i = 0; i < path.size(); i++)
            {
                cout << path[i] << " " << endl;
            }
        }
        return;
    }

    path.push_back(root->data);
    RootToLeavePathInRange(root->left, low, high, path, sum + root->data);
    RootToLeavePathInRange(root->right, low, high, path, sum + root->data);
    path.pop_back();
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    int left_height = height(root->left);
    int right_height = height(root->right);

    int factor_1 = left_diameter;
    int factor_2 = right_diameter;
    int factor_3 = left_height + right_height + 1;

    return max(factor_3, max(factor_1, factor_2));
}

class DiaPair
{
public:
    int height = 0;
    int diameter = 0;
};

DiaPair *diameterOptimized(Node *root)
{
    if (root == NULL)
    {
        DiaPair *base = new DiaPair();
        base->height = 0;
        base->diameter = 0;
        return base;
    }
    
    DiaPair *left = diameterOptimized(root->left);
    DiaPair *right = diameterOptimized(root->right);

    DiaPair *my_result = new DiaPair();
    my_result->height = max(left->height, right->height) + 1;
    my_result->diameter = max(left->height + right->height + 1, max(left->diameter, right->diameter));
    
    delete left;
    delete right;

    return my_result;
}

class BalPair
{
public:
    bool isBalanced;
    int height;
};

BalPair *checkBalanced(Node *root)
{
    if (root == NULL)
    {
        BalPair *base_pair = new BalPair();
        base_pair->height = 0;
        base_pair->isBalanced = true;
        return base_pair;
    }
    
    BalPair *left_pair = checkBalanced(root->left);
    BalPair *right_pair = checkBalanced(root->right);

    BalPair *my_pair = new BalPair();
    int gap = left_pair->height - right_pair->height;

    my_pair->height = max(left_pair->height, right_pair->height) + 1;
    my_pair->isBalanced = left_pair->isBalanced && right_pair->isBalanced && gap >= -1 && gap <= 1;

    return my_pair;
}

class BSTPair
{
public:
    bool isBST;
    int min;
    int max;

    int largest_subtree_size; //* these 2 variables are needed for the LargestBST function apart from the variables defined above
    int largest_subtree_root;
};

BSTPair *checkBST(Node *root)
{
    if (root == NULL)
    {
        BSTPair *base_pair = new BSTPair();
        base_pair->isBST = true;
        base_pair->max = INT_MIN;
        base_pair->min = INT_MAX;

        return base_pair;
    }
}

void display(Node *root)
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
    
    cout << "Diameter with O(n^2) complexity is " << endl;
    cout << diameter(root) << endl;
    cout << "DiameterOptimized with O(n) complexity is " << endl;
    cout << diameterOptimized(root)->diameter;
    cout << endl;
}
