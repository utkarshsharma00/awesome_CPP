#include<iostream>
using namespace std;

int main(int argc,char** argv){
    int number1,number2;
    cout<<"Enter 2 numbers to find their GCD"<<endl;
    cin>>number1>>number2;

    while(number1 % number2 != 0){
        int remainder = number1 % number2;
        number1 = number2;
        number2 =  remainder;

    }
cout<<"GCD is "<<number2;
}    