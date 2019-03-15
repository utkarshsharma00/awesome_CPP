#include<iostream>
using namespace std;

int main(int argc, char**argv){
    int x;
    cin>>x;

    for(int bn=31;bn>=0;bn--){
        int bm = 1<<bm;
        cout<<((x&bm)==0?0:10);
    }cout<<endl;
}