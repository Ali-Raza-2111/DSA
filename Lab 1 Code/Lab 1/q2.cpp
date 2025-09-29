#include <iostream>
using namespace std;

int main(){
    int a;
    cout<<"Enter a three digit Number\t";
    cin>>a;
    
    while (a>0)
    {
        cout<<a%10;
        a/=10;
    }
    
    return 0;
}