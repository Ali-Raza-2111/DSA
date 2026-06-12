#include <iostream>
using namespace std;
//Given an array of 5 integers, print each element on a new line using a for loop.
int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}