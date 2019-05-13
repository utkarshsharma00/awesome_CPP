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
  
    int handleRemoveWhenSizeis1()
    {
        int temp = head->data;
        delete head;
        head = tail = NULL;
        size = 0;
        return temp;
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
  
    void reversePointerRecursive(Node *node)
    {
        if (node->next == NULL)
        {
            return;
        }
        reversePointerRecursive(node->next);
        node->next->next = node; // is equal to saying that current->next = previous
        node->next = NULL;
    }
  
    void reverseDataRecursive(Node *right, int floor)
    {
      if (right == NULL)
        {
            return;
        }    
        reverseDataRecursive(right->next, floor + 1);
        if (floor >= size / 2)
        {
            int temp = reverseDataRecursiveLeft->data;
            reverseDataRecursiveLeft->data = right->data;
            right->data = temp;

            reverseDataRecursiveLeft = reverseDataRecursiveLeft->next;
        }
    }

    void displayReverse(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
      
        displayReverse(node->next);
        cout << node->data << " "; //once the node becomes NULL it falls from the stack and then prints the data while falling
    }
  
    bool isPalindrome(Node **left, Node *right)
    {
        if (right == NULL)
        {
            return true;
        }
        bool recursion_result = isPalindrome(left, right->next);
        bool my_result = recursion_result == true && (*left)->data == right->data;
        *left = (*left)->next;
        return my_result;     
     }
  
    void Fold(Node **left, Node *right, int floor)
    {
        if (right == NULL)
        {
            return;
        }
        Fold(left, right->next, floor + 1);
        if (floor > size / 2)
        {
            right->next = (*left)->next;
            (*left)->next = right;
            (*left) = right->next;
        }
        else if (floor == size / 2)
        {
            tail = right;
            tail->next = NULL;
        }
    }
      
    void Unfold(Node *temp1)
    {
        if (temp1->next == NULL)
        {
            head = tail = temp1;
            return;
        }
        else if (temp1->next->next == NULL)
        {
            head = temp1;
            tail = temp1->next;
            return;
        }
      
        Node *temp2 = temp1->next;
        Unfold(temp1->next->next);

        temp1->next = head;
        head = temp1;
        tail->next = temp2;
        tail = temp2;
        tail->next = NULL;
    }
  
    Node *midNode(Node *starting_point, Node *ending_point)
    {
      //yet to be written
    }

    LinkedList *MergeSort(Node *starting_point, Node *ending_point)
    {
        if (ending_point == starting_point)
        {
            LinkedList *newlist = new LinkedList();
            newlist->addLast(starting_point->data);
            return newlist;
        } 
      
        Node *mid = midNode(starting_point, ending_point);
        Node *temp = mid->next; //! this needs to be done because otherwise because of the 195th line NULL will be passed in 151 line no.
        mid->next = NULL;
        LinkedList *left = MergeSort(starting_point, mid);
        LinkedList *right = MergeSort(temp, ending_point);
        LinkedList *sorted = new LinkedList();
        sorted->merge2lists(*left, *right);
        return sorted;
    }


  public:
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
  
   ~LinkedList()
    {
        Node *temp = head;
        for (int i = 0; i < size; i++)
        {
            Node *toberemoved = temp;
            temp = temp->next;
            delete toberemoved;
        }
    }  
  
    void CLEAR(LinkedList *l) //this function is very good, do understand it once
    {
        l->head = NULL;
        l->tail = NULL;
        l->size = 0;
    }
  
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
  
    int getsize()
    {
        return size;
    }
  
    bool isEmpty()
    {
        return size == 0;
    }
  
    int removeFirst()
    {
        if (size == 0)
        {
            return -1;
        }
        else if (size == 1)
        {
            handleRemoveWhenSizeis1();
        }
        else
        {
            int temp = head->data;
            Node *newhead = head->next;
            delete head;
            head = newhead;
            size--;
            return temp;
        }
    }
  
    int removeLast()
    {
        if (size == 1)
        {
            return handleRemoveWhenSizeis1();
        }
        else
        {
            Node *s1 = getNodeAt(size - 2);
            s1->next = NULL;
            int temp = tail->data;
            delete tail;
            tail = s1;
            size--;
            return temp;
        }
    }
  
    int removeAt(int index)
    {
        if (index == 0)
        {
            return removeFirst();
        }
        else if (index == size - 1)
        {
            return removeLast();
        }
        else
        {
            Node *nm1 = getNodeAt(index - 1);
            Node *n = nm1->next;
            Node *np1 = n->next;
            int temp = n->data;
            nm1->next = np1;
            delete n;
            size--;
            return temp;        
        }
    }
  
    int getFirst()
    {
        if (size == 0)
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }
  
    int getLast()
    {
        if (size == 0)
        {
            return -1;
        }
        else
        {
            return tail->data;
        }
    }
  
    int getAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of  bound\n";
            return -1;
        }
        else
        {
            Node *temp = getNodeAt(index);
            return temp->data;
        }
    }
  
    void reverseDataIteratively()
    {
        for (int low = 0, high = size - 1; low <= high; low++, high--)
        {
            Node *last = getNodeAt(high);
            Node *first = getNodeAt(low);
            swap(first->data, last->data); //STL library function
        }
    }

    void reversePointerRecursion()
    {
        reversePointerRecursive(head);
        Node *temp = head;
        head = tail;
        tail = temp;
        tail->next = NULL;
    }
  
    void reverseDataRecursion()
    {
        reverseDataRecursiveLeft = head;
        reverseDataRecursive(head, 0);
    }
  
    void reverseDataPointer() //iteratively
    {
        Node *current = head;
        Node *current_forward = current->next; //node after the current node
        Node *current_backward = NULL;         //node before the cuurent node
        while (current != NULL)
        {
            current->next = current_backward;
            current_backward = current;
            current = current_forward;
            if (current_forward != NULL)
            {
                current_forward = current_forward->next;
            }
        }
      
        Node *temp = head; // I had forgot to do this !
        head = tail;
        tail = temp;      
    }

    void reverseDataPointer() //iteratively
    {
        Node *current = head;
        Node *current_forward = current->next; //node after the current node
        Node *current_backward = NULL;         //node before the current node
        while (current != NULL)
        {
            current->next = current_backward;
            current_backward = current;
            current = current_forward;
            if (current_forward != NULL)
            {
                current_forward = current_forward->next;
            }
        }

        Node *temp = head;
        head = tail;
        tail = temp;
    }

    void kreverse(int k) //Microsoft Interview Question
    {
        Node *slow = head;
        Node *fast = head;
      
        for (int i = 0; i < k; i++)
        {
            fast = fast->next;
        }
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;    
    }

    void oddeven()
    {
        LinkedList newlistO; //list containing odd nos
        LinkedList newlistE; //list containing even nos
        while (this->size > 0)
        {
            int temp = this->removeFirst();
            if (temp % 2 == 0)
            {
                newlistE.addLast(temp);
            }
            else
            {
                newlistO.addLast(temp);
            }
        }
      
        if (newlistO.size == 0) //if all the elements in the list are even
        {
            this->head = newlistE.head;
            this->tail = newlistE.tail;
            this->size = newlistE.size;
        }
      
        else if (newlistE.size == 0) //if all the elements in the list are odd
        {
            this->head = newlistO.head;
            this->tail = newlistO.tail;
            this->size = newlistO.size;
        }
      
        else //if the elements in the list are even and odd
        {
            newlistO.tail->next = newlistE.head;
            this->head = newlistO.head;
            this->tail = newlistE.tail;
            this->size = newlistO.size + newlistE.size;
        }
      
        CLEAR(&newlistO);
        CLEAR(&newlistE);

    }
  
    Node *midNode(Node *starting_point, Node *ending_point)
    {
        Node *slow_p = starting_point;
        Node *fast_p = starting_point;
        
        while (fast_p != ending_point && fast_p->next != ending_point)
        {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
        }
        return slow_p;
    }
  
    int midelement()
    {
        Node *mid = midNode(head, tail);
        return mid->data;
    }
  
    void remduplicate()
    {
        LinkedList newlist;
        while (this->size > 0)
        {
            int temp = this->removeFirst();
            if (newlist.size == 0 || newlist.tail->data != temp)
            {
                newlist.addLast(temp);
            }
        }
        this->head = newlist.head;
        this->tail = newlist.tail;
        this->size = newlist.size;

        CLEAR(&newlist);
    }

    void displayRev() //this public funtion calls the private function displayReverse(Node *node). This had to be done because private members can't be accessed by the objects of the class. Strong OOPS Concept required
    {
        displayReverse(head); 
    }
  
    int kthfromlast(int k)
    {
        Node *slow = head;
        Node *fast = head;
        for (int i = 0; i < k; i++)
        {
            fast = fast->next;
        }
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
      
    }

    void merge2lists(LinkedList &ml1, LinkedList &ml2)
    {
        Node *ml1temp = ml1.head;
        Node *ml2temp = ml2.head;
      
        while (ml1temp != NULL && ml2temp != NULL)
        {
            if (ml1temp->data < ml2temp->data)
            {
                this->addLast(ml1temp->data);
                ml1temp = ml1temp->next;
            }
            else
            {
                this->addLast(ml2temp->data);
                ml2temp = ml2temp->next;
            }
        }
      
        while (ml1temp != NULL)
        {
            this->addLast(ml1temp->data);
            ml1temp = ml1temp->next;
        }
      
        while (ml2temp != NULL)
        {
            this->addLast(ml2temp->data);
            ml2temp = ml2temp->next;
        }
    }

    LinkedList *MergeSort(Node *starting_point, Node *ending_point)
    { 
        LinkedList *s1 = MergeSort(this->head, this->tail);
        return s1;
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
  
    bool isPalin()
    {
        Node *left = head;
        Node *right = head;
        isPalindrome(&left, right);    
    }
  
    void fold()
    {
        Node *left = head;
        Node *right = head;
        Fold(&left, right, 0);
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
    ll.addAt(100, 3);  //the params are addAt(data, index)
    ll.display();
    ll.removeFirst(); 
    ll.removeFirst();
    ll.display();
    ll.removeLast(); 
    ll.display();
    ll.addLast(200); 
    ll.display();
    ll.removeAt(2); 
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
    delete ll1; // deleting the Dynamic Memory (that is memory that we created for our use) is very important otherwise it will lead to memory leak and one can see this in the Task Manager of Windows.
    
    LinkedList *ll2 = new LinkedList();
    ll2->addLast(10);
    ll2->addLast(20);
    ll2->addLast(30);
    ll2->reverseDataRecursion();
    ll2->display();
    ll2->displayRev();
    ll2->reverseDataPointer();  // yet to be thought off !
    ll2->reversePointerRecursion();
    ll2->addFirst(100);
    ll2->addLast(40);
    ll2->addLast(50);
    ll2->display();
    delete ll2;
    
    LinkedList *ll3 = new LinkedList(); //for checking palindrome function
    ll3->addLast(10);
    ll3->addLast(20);
    ll3->addLast(30);
    ll3->addLast(30);
    ll3->addLast(20);
    ll3->addLast(10);
    ll3->isPalin();
    cout << ll3->isPalin();
    ll3->addLast(40);
    ll3->display();
    delete ll3;
  
    LinkedList *ll4 = new LinkedList(); //for Fold
    ll4->addLast(10);
    ll4->addLast(20);
    ll4->addLast(30);
    ll4->addLast(40);
    ll4->addLast(50);
    ll4->addLast(60);
    ll4->fold();
    ll4->display();
    delete ll4;
  
    LinkedList *ll5 = new LinkedList(); //for UnFold
    ll5->addLast(10);
    ll5->addLast(70);
    ll5->addLast(20);
    ll5->addLast(60);
    ll5->addLast(30);
    ll5->addLast(50);
    ll5->addLast(40);
    ll5->unfold();
    ll5->addFirst(-1);
    ll5->addLast(100);
    ll5->display();
    delete ll5;
    
    LinkedList *ll6 = new LinkedList(); //for removeduplicate
    ll6->addLast(2);
    ll6->addLast(2);
    ll6->addLast(2);
    ll6->addLast(2);
    ll6->addLast(3);
    ll6->addLast(3);
    ll6->addLast(5);
    ll6->addLast(5);
    ll6->addLast(5);
    ll6->addLast(11);
    ll6->addLast(11);
    ll6->addLast(11);
    ll6->remduplicate();
    ll6->display();
    delete ll6;
  
    LinkedList *ll7 = new LinkedList(); //for OddEven
    ll7->addLast(2);
    ll7->addLast(7);
    ll7->addLast(4);
    ll7->addLast(9);
    ll7->addLast(3);
    ll7->addLast(18);
    ll7->addLast(6);
    ll7->addLast(11);
    ll7->oddeven();
    ll7->display();
    delete ll7;
  
    LinkedList *ll8 = new LinkedList(); //for kReverse
    ll8->addLast(2);
    ll8->addLast(7);
    ll8->addLast(4);
    ll8->addLast(9);
    ll8->addLast(3);
    ll8->addLast(18);
    ll8->addLast(6);
    ll8->addLast(11);
    ll8->kreverse(3);
    ll8->display();
    delete ll8;
  
    LinkedList *ll9 = new LinkedList(); //for midElement and kthfromlast
    ll9->addLast(10);
    ll9->addLast(20);
    ll9->addLast(30);
    ll9->addLast(40);
    ll9->addLast(50);
    ll9->addLast(60);
    ll9->addLast(70);
    ll9->addLast(80);
    cout << ll9->midelement();
    cout << "------------------------------" << endl;
    cout << ll9->kthfromlast(3);
    ll9->display();
    delete ll9;
  
    LinkedList ml1, ml2, ml3; //for merge2lists() //*ml means mergelist
    ml1.addLast(10);
    ml1.addLast(20);
    ml1.addLast(30);
    ml1.addLast(40);

    ml2.addLast(11);
    ml2.addLast(22);
    ml2.addLast(200);
    ml2.addLast(400);

    //! here ml3 will be automatically passed with the help of 'this'

    ml3.merge2lists(ml1, ml2);
    ml3.display();
  
    LinkedList *ll10 = new LinkedList(); // for mergesort
    ll10->addLast(2);
    ll10->addLast(7);
    ll10->addLast(4);
    ll10->addLast(9);
    ll10->addLast(3);
    ll10->addLast(18);
    ll10->addLast(6);
    ll10->addLast(11);

    LinkedList *ll11 = ll10->mergesort();
    ll11->display();
}
  
  
