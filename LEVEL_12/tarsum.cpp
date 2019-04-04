#include <iostream> //understand this code once again
#include <vector>

using namespace std;

vector<vector<int>> *tarsum(int arr[], int target, int starting_point, int size_of_array)
{
    if (starting_point == size_of_array)
    {
        vector<vector<int>> *br = new vector<vector<int>>();
        if (target == 0)
        {
            vector<int> khaali_vector;
            br->push_back(khaali_vector);
        }
        return br;
    }
    vector<vector<int>> *rr1 = tarsum(arr, target - arr[starting_point], starting_point + 1, size_of_array);
    vector<vector<int>> *rr2 = tarsum(arr, target, starting_point + 1, size_of_array);

    vector<vector<int>> *my_result = new vector<vector<int>>();

    for (int i = 0; i < rr1->size(); i++)
    {
        (*rr1)[i].push_back(arr[starting_point]);
        my_result->push_back((*rr1)[i]);
    }
    for (int i = 0; i < rr2->size(); i++)
    {
        my_result->push_back((*rr2)[i]);
    }

    delete rr1;
    delete rr2;
    return my_result;
}

int main(int argc, char **argv)
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    vector<vector<int>> *result = tarsum(arr, 70, 0, 7);
    for (int i = 0; i < result->size(); i++)
    {
        for (int j = 0; j < (*result)[i].size(); j++)
        {
            cout << (*result)[i][j];
        }
        cout << endl;
    }
}