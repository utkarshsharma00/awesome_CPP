#include <iostream>
#include <list>
#include <math.h>

using namespace std;

template <class K, class V>
    
class HashMap
{
    private:
    int no_of_elements;
    int no_of_buckets;

    class HashMap_Node
    {
    public:
        K key;
        V value;
        HashMap_Node(K key, V value)
        {
            this->key = key;
            this->value = value;
        }
    };
    
    //yet to be written
};

int main(int argc, char **argv)
{
    HashMap<string, int> map;
}
