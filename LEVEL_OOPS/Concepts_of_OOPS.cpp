#include <bits/stdc++.h>
using namespace std;

class study
{
  private:
    int roll_no;

  public:
    void add(int num1, int num2) //* can also be declared outside the class with the help of scope resolution operator F
    {
        int sum = num1 + num2;
        std ::cout << sum;
    }

    int getroll_no()
    {
        return roll_no;
    }

    int setroll_no(int i)
    {
        roll_no = i;
    }

    static int counter; //! counter variable cannot be assigned value here because ISO C++ forbids in-class initialization of non-const static member

    static const int counter_1 = 1; //! This also sorts the problem faced by line 26. This is basically the Inline definition.

    //TODO Notes:
    //* Static variables are not destroyed that is they keep their value through out the lifetime of the program.
    //* They are not associated with the objects of the class. Moreover static varibles even exist without the instantiation of an object.
    //* They are created when the program starts which is similar to global variables.
    //* Its better to think the Static members belonging to the class itself, and not to the Objects of the class

    static int object_counter;
    // study(int check_param) //*ctor
    // {
    //     check_param = -1;
    //     cout << "Constructor Called\n";
    //     object_counter++;
    // }

    static int getCount()
    {
        return object_counter;

        //TODO NOTES
        //* Static functions can be accessed using only the class name and scope resolution operator.
        //* A static function can only access static data members and other static member functions.
        //* It cannot access non-static data members because they must belong to class object and static member functions have no class objects to work with.
        //* This operator cannot be used because they are not attatched to an object.
        //* Static functions cannot be virtual.
        //* Member functions with the same name and name parameter type list cannot be overloaded if any of them is a static member function declaration.
    }

    //~study(); //* dtor
};

int study::counter = 1; //! due to the reason in comment on line 26 I had to declare it outside the class.

inline int Max_of_2(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;

    //TODO NOTES
    //* A function defined inside the class is automatically inline.
    //* The compiler will place the copy of this function at each point where the funtion is called at the compile time.
    //* Due to above point inline functions should be small because they increase efficiency and speed.
    //* Large inline functions cause Cache misses.
    //* Inline functions dont get storage , they are kept in the 'Symbol Table' which is a data structure implemented and maintained by the compiler itself.
    //* Symbol table basically tracks the semantics of the variables.
    //* As inline functions dont get storage space therefore they have no address and in case we want the address of the function it will not be possible if the function is Inline.
}

void static_object_function()
{
    static study object;

    //TODO NOTES
    //* The above is a static object ,therefore it has its scope till the end of the program's lifetime.
    //* Its dtor() will be called when the main function exits.
}

int main(int argc, char **argv)
{
    study object1, object2, object_to_test_static1, object_to_test_static2;
    object1.add(5, 7);
    cout << endl;
    object2.setroll_no(24);
    cout << object2.getroll_no();
    cout << endl;
    object_to_test_static1.counter = 2;
    cout << object_to_test_static1.counter << endl; //* The lines 47 to 49 prove that Static member variables are shared by all the objects.
    cout << object_to_test_static2.counter;
    cout << endl;
    // study object_to_test_static_funtion(100000);
    // cout << endl;
    // study::getCount();
    cout << "Inline funtion testing " << endl;
    cout << Max_of_2(10, 20);
}
