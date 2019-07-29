#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
    
class pq
{
    private:
    vector<T> list;
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
    
};

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
