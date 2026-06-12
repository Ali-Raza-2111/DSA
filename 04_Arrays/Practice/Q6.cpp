#include <iostream>
using namespace std;
// Given an array of N integers, count how many are even and how many are odd, then print both counts.
int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};

    int even = 0,odd = 0;

    for (int i = 0; i < size; i++)
    {
        if(arr[i]%2 == 0){
            even++;
        }else{
            odd++;
        }
    }
    
    cout<<"THe even number are "<<even<<endl;
    cout<<"The odd numbers are "<<odd<<endl;
    
    return 0;
}