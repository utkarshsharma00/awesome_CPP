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
  
  int previous = (*path1)[i]; //* can also be done as path1->at(i)
  while (i >= 0 && j >= 0 && path1->at(i) == path2->at(j))
  {
      previous = (*path1)[i];
      i--;
      j--;
  }
  return previous;
}

int distance(Node *root, int data1, int data2)
{
  vector<int> *path1 = Node2rootPath(root, data1);
  vector<int> *path2 = Node2rootPath(root, data2);
  
  int i = path1->size() - 1;
  int j = path2->size() - 1;
  while (i >= 0 && j >= 0 && path1->at(i) == path2->at(j))
  {
      i--;
      j--;
  }
  return (i + 1) + (j + 1) + 1;
}

void Mirror(Node *root)
{
  if (root == NULL)
  {
      return;
  }
  for (int i = 0; i < root->children.size(); i++)
  {
      Mirror(root->children[i]);
  }
  int left = 0;
  int right = root->children.size() - 1;
  while (left < right)
  {
      Node *leftNode = root->children[left];
      Node *rightNode = root->children[right];

      root->children[left] = rightNode;
      root->children[right] = leftNode;

      left++;
      right--;
  }
}

Node *linearize(Node *root) //O(n) complexity
{
  if (root->children.size() == 0)
  {
      return root;
  }
  Node *original_last = root->children.back();
  Node *original_last_tail = linearize(original_last);

  while (root->children.size() > 1)
  {
      Node *second_last = root->children[root->children.size() - 2];
      Node *second_last_tail = linearize(second_last);

      Node *last = root->children[root->children.size() - 1];
      root->children.pop_back();

      second_last_tail->children.push_back(last);
  }
  return original_last_tail;
}

bool areSimilarStructure(Node *node1, Node *node2)
{
  if (node1->children.size() != node2->children.size())
  {
      return false;
  }
  for (int i = 0; i < node1->children.size(); i++)
  {
      bool checker = areSimilarStructure(node1->children[i], node2->children[i]);
      if (checker == false)
      {
          return false;
      }
  }
  return true;
}

bool areMirrorSimilar(Node *node1, Node *node2)
{
  if (node1->children.size() != node2->children.size())
  {
      return false;
  }
  for (int i = 0; i < node1->children.size(); i++)
  {
      bool checker = areMirrorSimilar(node1->children[i], node2->children[node2->children.size() - 1 - i]);
      if (checker == false)
      {
          return false;
      }
  }
  return true;
}

bool isSymetric(Node *root)
{
  return areMirrorSimilar(root, root);
}

void MultiSolver(Node *root, int depth, int &MAX, int &MIN, int &Size_of_tree, int &Height, int &Ceil, int &Floor, int data)
{
  Size_of_tree++;
  Height = depth > Height ? depth : Height;
  MAX = root->data > MAX ? root->data : MAX;
  MIN = root->data < MIN ? root->data : MIN;
  
  if (root->data > data)
  {
      Ceil = min(root->data, Ceil);
  }

  if (root->data < data)
  {
      Floor = max(root->data, Floor);
  }
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
