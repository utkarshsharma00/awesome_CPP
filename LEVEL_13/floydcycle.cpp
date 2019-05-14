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

bool Detect(Node *n)
{
    bool loop = false;
    Node *slow = n;
    Node *fast = n;
  
    //yet to be written
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

int main(int argc, char **argv)
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    Node *n9 = new Node(9);
  
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n5;

    bool result = Detect(n1);
    cout << result;
    display(n1);
} 
