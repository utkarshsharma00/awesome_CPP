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
    
    int count(K key)
    {
        int bucket_index = get_bucket_index(key);
        auto data_index = get_data_index(bucket_index, key);
        
        if (data_index == buckets[bucket_index].end())
        {
            return 0;
        }

        else
        {
            return 1;
        }
    }
    
    V &operator[](const K &key)
    {
        int bucket_index = get_bucket_index(key);
        auto data_index = get_data_index(bucket_index, key);
        
        if (data_index == buckets[bucket_index].end())
        {
            HashMap_Node node(key, V());
            buckets[bucket_index].push_back(node);
            no_of_elements++;

            return buckets[bucket_index].back().value;
        }
        
        else
        {
            return data_index->value;
        }

        // double lambda = no_of_elements * 1.0 / no_of_buckets;
        // if (lambda > 2.0)
        // {
        //     rehash();
        // }
    }
    
    int size()
    {
        return no_of_elements;
    }

    void remove(K key)
    {
        int bucket_index = get_bucket_index(key);
        auto data_index = get_data_index(bucket_index, key);
        
        if (data_index == buckets[bucket_index].end())
        {
        }

        else
        {
            buckets[bucket_index].erase(data_index);
        }
    }

    void display()
    {
        cout << "-------------------------------" << endl;

        for (int bucket_index = 0; bucket_index < no_of_buckets; bucket_index++)
        {
            cout << bucket_index << ". ";
            for (auto itr = buckets[bucket_index].begin(); itr != buckets[bucket_index].end(); itr++)
            {
                cout << "[" << itr->value << "@" << itr->key << "]";
            }
            cout << endl;
        }

        cout << "-------------------------------" << endl;
    }
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
