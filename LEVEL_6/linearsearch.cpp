#include<iostream>
using namespace std;

int main(int argc,char** argv){
    int arr[]={50,60,70,90,2,33,-14,61};
    int find;
    cin>>find;

    for(int i=0;i<8;i++){
        if(find == arr[i]){
            cout<<i;
            return 0;
            }
            
}
cout<<-1;
}