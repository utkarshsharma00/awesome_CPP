#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
    
class pq
{
  private:
    vector<T> list;
    bool (*comptor)(const T &o1, const T &o2) = NULL; //!this NULL has to be done only for the constructor created in line 82

    void swap(int i, int j)
    {
        T ith = list[i];
        T jth = list[j];
        list[i] = jth;
        list[j] = ith;
    }
    
    // if i is higher priority return true, else return false
    bool ishp(int i, int j)
    {
        if (this->comptor == NULL)
        {
            return list[j] < list[i];
        }
        else
        {
            return comptor(list[i], list[j]);
        }
    }
    
    void upheapify(int i)
    {
        if (i == 0)
            return;

        int pi = (i - 1) / 2;
        if (ishp(i, pi) == true)
        {
            swap(i, pi);
            upheapify(pi);
        }
    }
    
  public:
    pq()
    {
        this->comptor = NULL;
    }

    pq(bool (*comptor)(const T &o1, const T &o2))
    {
        this->comptor = comptor;
    }
    
    void push(T val)
    {
        list.push_back(val);
        upheapify(list.size() - 1);
    }
    
    T top()
    {
        return list[0];
    }

    int size()
    {
        return list.size();
    }
};
    
class Student
{
  public:
    int marks;
    int extra;
    string name;
    
    bool operator<(const Student &o) const
    {
        return this->name.compare(o.name) < 0;
    }

    Student(int marks, int extra, string name)
    {
        this->marks = marks;
        this->extra = extra;
        this->name = name;
    }
    
    void display()
    {
        cout << "[" << this->name << ":" << this->marks << ", "
             << this->extra << "]" << endl;
    }
};

bool StudentMarksComparator(const Student &o1, const Student &o2)
{
    return o2.marks < o1.marks;
}

bool StudentExtraComparator(const Student &o1, const Student &o2)
{
    return o2.extra < o1.extra;
}

bool StudentMarksExtraComparator(const Student &o1, const Student &o2)
{
    
}

bool StudentExtraMarksComparator(const Student &o1, const Student &o2)
{
    
}

int main(int argc, char **argv)
{
    pq<Student> pq(StudentExtraMarksComparator);

    pq.push(Student(8, 8, "D"));
    pq.push(Student(5, 5, "E"));
    pq.push(Student(10, 10, "A"));
    pq.push(Student(6, 10, "B"));
    pq.push(Student(10, 2, "C"));

    while (pq.size() > 0)
    {
        Student s = pq.top();
        pq.pop();
        s.display();
    }
}
