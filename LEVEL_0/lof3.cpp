#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int a=10;
    int b=20;
    int c=30;

    if(a>=b && a>=c){
        cout<<"a = "<<a<<"is largest";
    }else{
        if(b>=c){
            cout<<"b = "<<b<<"is largest";
        }
        else{
                cout<<"c = "<<c<<"is largest";
    }
}

}