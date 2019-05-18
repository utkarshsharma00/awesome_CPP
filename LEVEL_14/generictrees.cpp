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
  for (int i = 0; i < datalist.size(); i++)
    {
        if (datalist[i] == -1)
        {
            newlist->pop_back();
        }
    //yet to be written 
    return root;
}

int maxintree(Node *root)
{
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

bool findintree(Node *root, int data_to_find)
{
  //yet to be written 
}

int sizeoftree(Node *root)
{
  int count = 0;
  for (int i = 0; i < root->children.size(); i++)
  {
      count += sizeoftree(root->children[i]);
  }
  return count + 1; //* +1 because of 10. The for loop above is our faith that 20,30 and 40 will give their sizes 
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
