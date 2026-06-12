#include <iostream>
using namespace std;
//Given an array and a target value, search for the target and print its index if found, or print -1 if not found.



int main(){
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    int target = 7;
    for (int i = 0; i < size; i++)
    {
        if(target == arr[i]){
            cout<<"The index of target is "<<i<<endl;
        }
        if(i==size-1 && target !=arr[i]){
            cout<<"The target cannot be found the index is -1"<<endl;
        }
    }
    

    
    return 0;
}