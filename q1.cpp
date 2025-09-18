#include <iostream>
using namespace std;


int main(){
    int a,b;
    cout<<"Enter first number ";
    cin>>a;
    cout<<"Enter second number";
    cin>>b;
    cout<<"Before Swaping "<<a<<" "<<b<<endl;
    int temp = a;
    a = b;
    b = temp;
    cout<<"After Swaping "<<a<<" "<<b;

    return 0;
}