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

class EulerHelper
{
public:
  Node *root;
  int state;
  EulerHelper(Node *root, int state)
  {
      this->root = root;
      this->state = state;
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
  for (int i = 0; i < root->children.size(); i++)
  {
      MultiSolver(root->children[i], depth + 1, MAX, MIN, Size_of_tree, Height, Ceil, Floor, data);
  }
}

void Predecessor_Successor(Node *root, int &predecessor, int &successor, int &state, int data) //* 1st way
{
  if (state == 0)
  {
      if (root->data != data)
      {
          predecessor = root->data;
      }
      else
      {
          state++;
      }
  }
  else if (state == 1)
  {
      successor = root->data;
      state++;
  }
  
  for (int i = 0; i < root->children.size(); i++)
  {
      Predecessor_Successor(root->children[i], predecessor, successor, state, data);
  }
}

void predecessor_successor_way2(Node *root, int &pred, int &succ, int &prev, int &curr, int data)
{
  prev = curr;
  curr = root->data;
  if (curr == data)
  {
      pred = prev;
  }
  else if (prev == data)
  {
      succ = curr;
  }
  for (int i = 0; i < root->children.size(); i++)
  {
      predecessor_successor_way2(root->children[i], pred, succ, prev, curr, data);
  }
}

int kthSmallest(Node *root, int k)
{
  int result = INT_MIN;

  for (int i = 0; i < k; i++)
  {
      int Size = 0;
      int height = 0;
      int mn = INT_MAX; //minimum = mn
      int mx = INT_MIN; // maximum = mx
      int Ceil = INT_MAX;
      int Floor = INT_MIN;

      MultiSolver(root, 0, mx, mn, Size, height, Ceil, Floor, result);
      result = Ceil;
  }
  return result;
}

int kthLargest(Node *root, int k)
{
  int result = INT_MAX;

  for (int i = 0; i < k; i++)
  {
      int Size = 0;
      int height = 0;
      int mn = INT_MAX; //minimum = mn
      int mx = INT_MIN; // maximum = mx
      int Ceil = INT_MAX;
      int Floor = INT_MIN;

      MultiSolver(root, 0, mx, mn, Size, height, Ceil, Floor, result);
      result = Floor;
  }
  return result;
}

void LevelOrder(Node *root) //* #include<list> has to be included
{
  list<Node *> queue;
  queue.push_back(root);
  while (queue.size() > 0)
  {
      Node *front = queue.front();
      queue.pop_front();
      cout << front->data << " ";

      for (int i = 0; i < front->children.size(); i++)
      {
          queue.push_back(front->children[i]);
      }
  }
  cout << endl;
}

void LevelOrderLineByLine(Node *root)
{
  list<Node *> *current_queue = new list<Node *>();
  list<Node *> *next_queue = new list<Node *>();
  current_queue->push_back(root);
  while (current_queue->size() > 0)
  {
      Node *front = current_queue->front();
      current_queue->pop_front();
      cout << front->data << " ";

      for (int i = 0; i < front->children.size(); i++)
      {
          next_queue->push_back(front->children[i]);
      }
      if (current_queue->size() == 0)
      {
          delete current_queue;
          current_queue = next_queue;
          next_queue = new list<Node *>();
          cout << endl;
      }
   }

   delete current_queue;
   delete next_queue;
}

void LevelOrderZigZag(Node *root)
{
  list<Node *> *current_queue = new list<Node *>();
  list<Node *> *new_stack = new list<Node *>();
  bool left_to_right = true;
  current_queue->push_back(root);
  while (current_queue->size() > 0)
  {
      Node *front = current_queue->front();
      current_queue->pop_front();
      cout << front->data << " ";
      if (left_to_right)
      {
          for (int i = 0; i < front->children.size(); i++)
          {
              new_stack->push_front(front->children[i]); //* dont do push_back() , its a stack !
          }
      }
    
      else
      {
          for (int i = front->children.size() - 1; i >= 0; i--)
          {
              new_stack->push_front(front->children[i]); //* dont do push_back() , its a stack !
          }
      }
    
      if (current_queue->size() == 0)
      {
          delete current_queue;
          current_queue = new_stack;
          new_stack = new list<Node *>();
          left_to_right = !left_to_right; //had to be toggled not !=
          cout << endl;
      }
  }
  delete current_queue;
  delete new_stack;
}

void Euler(Node *root) //this uses EulerHelper Class
{
  list<EulerHelper *> stack;
  EulerHelper *rootHelper = new EulerHelper(root, 0);
  stack.push_front(rootHelper);

  while (stack.size() > 0)
  {
      EulerHelper *topHelper = stack.front();
      if (topHelper->state == 0)
      {
          cout << topHelper->root->data << " Pre" << endl;
          topHelper->state++;
      }
      else if (topHelper->state >= 1 && topHelper->state <= topHelper->root->children.size())
      {
          EulerHelper *childHelper = new EulerHelper(topHelper->root->children[topHelper->state - 1], 0);
          stack.push_front(childHelper);
          if (topHelper->state >= 2)
          {
              cout << topHelper->root->data << " In" << topHelper->state - 1 << endl;
          }
          topHelper->state++;
      }
      else if (topHelper->state == topHelper->root->children.size() + 1)
      {
          cout << topHelper->root->data << " Post" << endl;
          topHelper->state++;
      }
      else if (topHelper->state == topHelper->root->children.size() + 2)
      {
          stack.pop_front();
          delete topHelper;
      }
   }
}

void display(Node *root)
{
  cout << root->data << "->";
  for (int i = 0; i < root->children.size(); i++)
  {
      cout << root->children[i]->data << " ";
  }
  cout << " . " << endl;
  for (int i = 0; i < root->children.size(); i++)
  {
      display(root->children[i]);
  }
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
    cout << "Find in tree 0/1 \n"<< findintree(root, 900) << endl; //* Test other cases as well

    cout << "Node to root path is \n";
    vector<int> *myresult = Node2rootPath(root, 50);
    for (int i = 0; i < myresult->size(); i++)
    {
       cout << (*myresult)[i] << " ";
    }
    cout << endl;

    cout << "Least common ancestor is " << lowestcommonancestor(root, 70, 120);
    cout << endl;
    cout << "Distance between the 2 nodes is " << distance(root, 70, 120);
    cout << "----------------------" << endl;

    cout << "Mirror display is " << endl;
    //Mirror(root); //TODO uncomment this for running the mirror function.
    display(root);
    display(root2);
    cout << "Linearizing the tree " << endl;
    linearize(root);
    display(root);
  
    cout << "Are similar structure? " << endl;
    cout << areSimilarStructure(root, root2) << endl;

    cout << "Are Mirror Similar? " << endl;
    Mirror(root);
    cout << areMirrorSimilar(root, root3) << endl;

    cout << "Foldable ? " << endl;
    cout << isSymetric(root);
  
    cout << "MultiSolver funtion " << endl;
    int size = 0;
    int height = 0;
    int MIN = INT_MAX;
    int MAX = INT_MIN;
    int Ceil = 1000000000;
    int Floor = -100000000;
  
    display(root);
    MultiSolver(root, 0, MAX, MIN, size, height, Ceil, Floor, 10);
    if (Ceil == 1000000000)
    {
        Ceil = 1; //*this is done for handling the edge case, told by sir. Otherwise no need of doing these both if conditions for Ceil and Floor
    }
    if (Floor == -100000000)
    {
        Floor = -1;
    }
    cout << "Size = " << size << endl;
    cout << "Height = " << height << endl;
    cout << "MAX = " << MAX << endl;
    cout << "MIN = " << MIN << endl;
    cout << "Ceil = " << Ceil << endl;
    cout << "Floor = " << Floor << endl;
  
    cout << "Predecessor and Successor" << endl;
    int predecessor = -1;
    int successor = -1;
    int state = 0;
    Predecessor_Successor(root, predecessor, successor, state, 60);
    cout << predecessor << " & " << successor << " & " << state;
    
    cout << "\nPredecessor and Successor WAY 2" << endl;
    int pred = -1;
    int succ = -1;
    int current = 0;
    int previous = 0;
    predecessor_successor_way2(root, pred, succ, previous, current, 60);
    cout << pred << " & " << succ << endl;
  
    cout << "kth Largest is " << kthLargest(root, 3) << endl;
    cout << "kth Smallest is " << kthSmallest(root, 2) << endl;
    cout << endl;
    cout << endl;
    cout << endl;
  
    cout << "--------------------------------TRAVERSALS-----------------------------------" << endl;
    cout << "BFS " << endl;
    LevelOrder(root);
    cout << endl;
    cout << "Line By Line" << endl;
    LevelOrderLineByLine(root);
    cout << endl;
    cout << "ZIG ZAG" << endl;
    LevelOrderZigZag(root);
    cout << endl;
}
