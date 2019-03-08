#include<iostream>
using namespace std;

int main(int argc,char** argv){
    int number;
    cout<<"Enter any number\n";
    cin>>number;
    
    int remainder;
    while(number>0){
        remainder = number%10;
        cout<<remainder;
        number = number/10;
    }

 
    
}