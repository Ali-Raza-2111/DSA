#include <iostream>
using namespace std;
// Given an array of N integers, calculate and print the sum of all elements.
int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};

    int sum = 0;
    for (int st = 0; st < size; st++)
    {
        sum+=arr[st];
    }
    

    cout<<"Sum of the array is "<<sum<<endl;

    return 0;
}