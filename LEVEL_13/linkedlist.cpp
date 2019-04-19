#include <iostream> //This has all the codes
#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
  private:
    class Node
    {
      public:
        int data;
        Node *next;
    };
  
    Node *head;
    Node *tail;
    int size;
    
    void handleAddWhenSizeis0(int data)
    {
        Node *nn = new Node(); //nn means newnode
        nn->data = data;
        nn->next = NULL;
        head = tail = nn;
        size = 1;
    }
  
    Node *getNodeAt(int index)
    {
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

  public:
    void addFirst(int data)
    {
        if (size == 0)
        {
            handleAddWhenSizeis0(data);
        }
        else
        {
            Node *temp = new Node();
            temp->data = data;
            temp->next = NULL;
            temp->next = head;
            head = temp;
            size++;
        }
    }
  
    void addLast(int data)
    {
        if (size == 0)
        {
            handleAddWhenSizeis0(data);
        }
        else
        {
            Node *nn = new Node(); //nn means new node
            nn->data = data;
            nn->next = NULL;
            tail->next = nn;
            tail = nn;
            size++;
        }
    }
  
    void addAt(int data, int index)
    {
        if (index < 0 || index > size)
        {
            return;
        }
        else if (index == 0)
        {
            addFirst(data);
        }
        else if (index == size)
        {
            addLast(data);
        }
        else
        {
            Node *nm1 = getNodeAt(index - 1); //need to write the getNodeAt(index) function first !
            Node *np1 = nm1->next;
            Node *n = new Node();
            n->data = data;
            nm1->next = n;
            n->next = np1;
            size++;
        }
    }
  
    void display()
    {
        Node *temp = head;
        for (int i = 0; i < size; i++)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};  

int main(int argc,char **argv)
{
    cout << "By Stack\n";
    LinkedList ll; // this creates the ll in Stack 
    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(30);
    ll.display();
    ll.addFirst(40);
    ll.addFirst(50);
    ll.display();
    ll.addAt(100, 3); //yet to be written, the params are addAt(data, index)
    ll.display();
    //ll.removeFirst(); //yet to be written
    //ll.removeFirst();
    ll.display();
    //ll.removeLast(); //yet to be written
    ll.display();
    ll.addLast(200); 
    ll.display();
    //ll.removeAt(2); //yet to be written
    ll.display();
  
    cout << "By heap\n"; //2nd way
    LinkedList *ll1 = new LinkedList();
    ll1->addLast(10);
    ll1->addLast(20);
    ll1->addLast(30);
    ll1->addLast(40);
    ll1->addLast(50);
    ll1->addLast(60);
    ll1->display();
    delete ll1;
}
  
  
