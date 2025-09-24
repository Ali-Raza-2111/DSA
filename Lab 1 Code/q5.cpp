#include <iostream>
using namespace std;

int main(){
    int limit = 100;
    int sum = 0;

    for (int i = 1; i <=100 ; i++)
    {
        sum+=i;
    }

    cout<<"The sum first "<<limit<<" integers is "<<sum<<endl;
     
    return 0;
}