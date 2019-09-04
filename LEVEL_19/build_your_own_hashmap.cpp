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
    
    list<HashMap_Node> *buckets = NULL;

    int get_bucket_index(K key)
    {
        int hash_code = hash<K>()(key);
        hash_code = abs(hash_code);
        return hash_code % no_of_buckets;
    }
    
public:
    HashMap()
    {
        no_of_buckets = 4;
        no_of_elements = 0;
        buckets = new list<HashMap_Node>[no_of_buckets];
    }
    
    int size()
    {
        return no_of_elements;
    }

    void remove(K key)
    {
        int bucket_index = get_bucket_index(key);
        auto data_index = get_data_index(bucket_index, key);
        //yet to be written
    }

    void display()
    {
        //yet to be written
    }

    //yet to be written
};

int main(int argc, char **argv)
{
    HashMap<string, int> map;
    
    map["India"] = 10;
    map["Pak"] = 8;
    map["Sweden"] = 120;
    map["canada"] = 8;
    map["japan"] = 10;
    map["Paukk"] = 8;
    map["usa"] = 10;
    map["hgjds"] = 8;
    map["sfaf"] = 10;
    map["fas"] = 8;
    cout << map.count("India") << " " << map.count("Pak") << endl;

    cout << map["India"] << endl;
    map.display();
}
