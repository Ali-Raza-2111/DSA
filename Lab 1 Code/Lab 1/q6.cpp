#include <iostream>
using namespace std;

int getUpperLimit(){
    int limit;
    cout<<"Enter the limit\t";
    cin>>limit;
    if (limit>1000)
    {
        cout<<"Please enter valid Limit\n";
        return 0;
    }else{
        return limit;
    }
    
}

int sumOfEven(int num){
    int sum = 0;
    for (int i = 0; i <=num; i+=2)
    {
        sum+=i;
    }

    return sum;
    
}
int main(){
    int num = getUpperLimit(); 
    int sum = sumOfEven(num);

    cout<<"Even Numbers from 0 to "<<num<<" = "<<sum;
    return 0;
}