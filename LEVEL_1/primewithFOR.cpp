#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int number;
    int divisor = 2;

    cout<<"Enter any number to check its prime or not\n";
    cin>>number;

    for(divisor = 2; (divisor*divisor) <= number; divisor++){
        if(number%divisor == 0){
            cout<<"It is not prime";
            return 0;
        
        }
        
    }
    cout<<number<<"is prime";
}