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
}
