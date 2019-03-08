#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int s1, s2, e1, e2;

    cin >> s1 >> e1 >> s2 >> e2;

    if(s2 >= s1 && e2 <= e1){
        cout << "e2 is in e1";
    } else if(s1 >= s2 && e1 <= e2){
        cout << "e1 is in e2";
    } else if(s2 > e1 || e2 < s1){
        cout << "no overlap";
    } else {
        cout << "partial";
    }
}