#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
    }
};

void RemoveLoop(Node *slow, Node *fast)
{
    Node *prev = NULL;
    while (slow != fast)
    {
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    cout << fast->data << endl;
    prev->next = NULL;
}

void display(Node *n)
{   
    cout<<endl;
    for (Node *temp = n; temp != NULL; temp = temp->next)
    {
        cout << temp->data << " ";
    }
    cout << endl;
}
