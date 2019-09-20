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
    else if (data > root->data)
    {
        return find(root->right, data);
    }
    else if (data < root->data)
    {
        return find(root->left, data);
    }
    else
    {
        return true;
    }
}

void Print_In_Range(Node *root, int low, int high)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data < low)
    {
        Print_In_Range(root->right, low, high);
    }
    else if (root->data > high)
    {
        Print_In_Range(root->left, low, high);
    }
    else
    {
        Print_In_Range(root->left, low, high);
        cout << root->data << endl;
        Print_In_Range(root->right, low, high);
    }
}

void Replace_with_Sum_of_Larger_nodes(Node *root, int &sum)
{
    if (root == NULL)
        return;

    Replace_with_Sum_of_Larger_nodes(root->right, sum);

    int orignal_data = root->data;
    root->data = sum;
    sum += orignal_data;

    Replace_with_Sum_of_Larger_nodes(root->left, sum);
}

void Pair_Sum_Target(Node *root, int target, Node *original_root) //* O(nlogn)
{
    if (root == NULL)
    {
        return;
    }

    int Complement = target - root->data;
    if (root->data < Complement)
    {
        if (find(original_root, Complement) == true) //* find() function has O(logn) complexity for BST
        {
            cout << root->data << " " << Complement << endl;
        }
    }

    Pair_Sum_Target(root->left, target, original_root); //* These 2 statements contribute to O(n)
    Pair_Sum_Target(root->right, target, original_root);
}

Node *Add_node_in_the_tree(Node *root, int data)
{
    if (root == NULL)
    {
        Node *newnode = new Node(data);
        return newnode;
    }
  
    if (data > root->data)
    {
        root->right = Add_node_in_the_tree(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = Add_node_in_the_tree(root->left, data);
    }

    return root;
}

Node *Remove_node_from_tree(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
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

int CountBST(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }

    int count = 0;
    for (int i = 0; i < num; i++)
    {
        count += CountBST(i) * CountBST(num - i - 1);
    }

    return count;
}

int main(int argc, char **argv)
{
    vector<int> datalist{12, 25, 37, 50, 62, 75, 87};
    Node *root = construct(datalist, 0, datalist.size() - 1);
    display(root);
    cout << "Min is " << endl;
    cout << Min(root) << endl;
    cout << "Max is " << endl;
    cout << Max(root) << endl;
    cout << "Find in tree " << endl;
    cout << find(root, 87) << endl;
    cout << "Path in Range " << endl;
    Print_In_Range(root, 12, 72);
    cout << endl;

    vector<int> datalist1{10, 20, 30, 50, 60, 70, 80};
    Node *root1 = construct(datalist, 0, datalist.size() - 1);
  
    cout << "Replace with sum of Larger Nodes " << endl;
    int sum = 0;
    Replace_with_Sum_of_Larger_nodes(root1, sum);
    display(root1);

    cout << "Pair Sum Target " << endl;
    Pair_Sum_Target(root, 100, root);
  
    cout << endl;
    cout << "Number of distinct BST if we have distinct elements in the array (bonus question)" << endl;
    cout << CountBST(5);
  
    cout << endl;
    cout << "Add a node in the tree " << endl;
    Add_node_in_the_tree(root, 68);
    display(root);
    cout << endl;
    //yet to be written
}
