#include <iostream>
using namespace std;
// Given an array, print its elements in reverse order. Do NOT create a second array — just print from the last index to the first.

int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    for (int i = size-1; i >=0; i--)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}