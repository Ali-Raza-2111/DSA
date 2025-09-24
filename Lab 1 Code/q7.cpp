#include <iostream>
using namespace std;

int facByIter(int n){
    int fac = 1;
    for (int i = 1; i <=n; i++)
    {
        fac *= i;
    }
    return fac;
    
}

int facByRec(int n){
    if (n == 1)
    {
        return 1;
    }else{
        return n* facByRec(n-1);
    }
    
}
int main(){
    int num = 5;
    // int fac = facByIter(num);
    int fac = facByRec(num);
    cout<<"Factorial is "<<fac;
    return 0;
}