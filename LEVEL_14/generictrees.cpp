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
      else
      {
          Node *newnode = new Node(datalist[i]);
          if (newlist->size() == 0)
          {
              root = newnode;
          }
          else
          {
              Node *lastNode = newlist->back();
              lastNode->children.push_back(newnode);
          }
          newlist->push_back(newnode);
        }
    }
  return root;
}

int maxintree(Node *root)
{
  int max = root->data;
  for (int i = 0; i < root->children.size(); i++)
  {
      int fakemax = maxintree(root->children[i]);
      if (max < fakemax)
      {
          max = fakemax;
      }
  }
  return max; 
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
  if (root->data == data_to_find)
  {
      return true;
  }
  for (int i = 0; i < root->children.size(); i++)
  {
      bool find = findintree(root->children[i], data_to_find);
      if (find == true)
      {
         return true;
      }
    }
   return false;
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

vector<int> *Node2rootPath(Node *root, int data_to_find)
{
  if (root->data == data_to_find)
  {
      vector<int> *baseresult = new vector<int>();
      baseresult->push_back(data_to_find);
      return baseresult;
  }
  for (int i = 0; i < root->children.size(); i++)
  {
      vector<int> *fakeresult = Node2rootPath(root->children[i], data_to_find); //! another easy way of "for(Node* child:root->children)"
      if (fakeresult != NULL)
      {
          fakeresult->push_back(root->data);
          return fakeresult;
      }
  }
  return NULL;
}

int lowestcommonancestor(Node *root, int data1, int data2)
{
  vector<int> *path1 = Node2rootPath(root, data1);
  vector<int> *path2 = Node2rootPath(root, data2);

  int i = path1->size() - 1;
  int j = path2->size() - 1;

  //yet to be written
}

int distance(Node *root, int data1, int data2)
{
  //yet to be written 
}

void Mirror(Node *root)
{
  //yet to be written 
}

Node *linearize(Node *root) //O(n) complexity
{
  //yet to be written 
}

bool areSimilarStructure(Node *node1, Node *node2)
{
  //yet to be written 
}

void display(Node *root)
{
  cout << root->data << "->";
  for (int i = 0; i < root->children.size(); i++)
  {
      cout << root->children[i]->data << " ";
  }
  //yet to be written 
}

int main(int argc, char **argv) //TODO calling the functions is a tricky task in this code
{
    vector<int> list{
        10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = construct(list);
    display(root);
    cout << "Size of tree is " << sizeoftree(root) << endl;
    cout << "Height of tree is " << height(root) << endl;
    cout << "Max in tree is " << maxintree(root) << endl;
}
