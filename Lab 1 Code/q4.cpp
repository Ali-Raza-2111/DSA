#include <iostream>
using namespace std;

int main(){
    float r,dia,circum,area;
    cout<<"Enter Radius of Circle\t";
    cin>>r;
    
    dia = r*2;
    cout<<"Diameter of Circle is \t"<<dia<<endl;
    circum = 2*3.14*r;
    cout<<"Circumference of Circle is \t"<<circum<<endl;
    area = 3.14 *r *r ;
    cout<<"Area of Circle is \t"<<area<<endl;

    
    return 0;
}