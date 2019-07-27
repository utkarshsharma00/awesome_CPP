#include <iostream> //!tough question

using namespace std;

class kstacks
{
private:
    int cap;
    int *data_arr;
    int *pt_arr; //*pointer_array
    int *sha;    //* stack_head_array
    int fh;      //*free_head
};

int main(int argc, char **argv)
{
    kstacks ks(10, 3);
    
    ks.push(10, 0);
    ks.push(20, 0);
    ks.push(30, 1);
    ks.push(40, 2);
    ks.push(50, 2);
    ks.push(60, 1);
    ks.push(70, 1);
    ks.push(80, 2);
    ks.push(90, 0);
    ks.push(100, 0);
    ks.push(110, 2);
}
