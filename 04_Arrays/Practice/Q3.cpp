#include <iostream>
using namespace std;
//Given an array of N integers, find and print the largest element without using any built-in function.
int main(){
    int size = 5;
    int arr[size] = {1,2,3,7,5};

    int largest = arr[0];
    
    for (int i = 0; i < size; i++)
    {
        if(largest<arr[i]){
            largest = arr[i];
        }
    }

    cout<<"Largest Elemet is "<<largest<<endl;
    
    return 0;
}