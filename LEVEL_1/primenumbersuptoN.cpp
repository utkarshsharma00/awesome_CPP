#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
    int n;
    cout<<"Enter a number upto which you want to list all the prime numbers"<<endl;
    cin >> n;
    
    for (int i = 2; i <= n; i++)
    {   bool iisprime=true;
        int div=2;
        while (div * div <= i)
        {
            if (i % div == 0)
            {
                iisprime= false;
                
            }
            div++;
        }
        if(iisprime==true){
            cout<<i<<"\t";
        }
    }
    
}