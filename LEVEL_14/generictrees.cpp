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
  Node *root = NULL;
  vector<Node *> *newlist = new vector<Node *>();
  //yet to be written 
}

int height(Node *root)
{    
  int virtualheight = 0;
  for (int i = 0; i < root->children.size(); i++)
  {
     int fakeheight = height(root->children[i]); //* fakeheight is actually our faith that 20,30 and 40 will give their heights
     if (virtualheight < fakeheight)
     {
        virtualheight = fakeheight;
     }
   }
   return virtualheight + 1; //* +1 because of 10. The for loop above is our faith that 20,30 and 40 will give their height
}

int sizeoftree(Node *root)
{
  //yet to be written 
}

void display(Node *root)
{
  //yet to be written 
}

int main(int argc, char **argv) //TODO calling the functions is a tricky task in this code
{
    vector<int> list{
        10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = construct(list);

}
