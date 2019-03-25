#include <iostream> // this code has a time complexity of O(n^2)
using namespace std;

int main(int argc, char **argv)
{
    int arr[4][5] = {
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35},
        {41, 42, 43, 44, 45}};

    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(int);
    //int rows_counter = 0;
    //int cols_counter = 0;
    int counter = 1;
    int total_no_elements = rows * cols;
    int i, j = 0;
    int min_rows = 0;
    int min_cols = 0;
    int max_rows = rows - 1;
    int max_cols = cols - 1;

    while (counter <= total_no_elements) //counter variable actually just counts the total no of elements that have been traversed in the whole spiral via the 4 for loops
    {
        for (i = min_rows; i <= max_rows && counter <= total_no_elements; i++)
        {
            cout << arr[i][min_cols] << '\t';
            counter++;
        }
        min_cols++; //doing this actually prevents the corner element to be traversed twice
        for (j = min_cols; j <= max_cols && counter <= total_no_elements; j++)
        {
            cout << arr[max_rows][j] << '\t';
            counter++;
        }
        max_rows--;
        for (i = max_rows; i >= min_rows && counter <= total_no_elements; i--)
        {
            cout << arr[i][max_cols] << '\t';
            counter++;
        }
        max_cols--;
        for (j = max_cols; j >= min_cols && counter <= total_no_elements; j--) // did not put = sign in j>=min_cols
        {
            cout << arr[min_rows][j] << '\t';
            counter++;
        }
        min_rows++;
    }
    //cout << arr[i][j] << '\t';
}