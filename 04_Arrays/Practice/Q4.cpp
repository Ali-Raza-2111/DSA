#include <iostream>
using namespace std;
//Smallest element of an array
int main(){
    int size = 5;
    int arr[size] = {1,2,3,7,5};

    int smallest = arr[0];
    
    for (int i = 0; i < size; i++)
    {   
        if(smallest > arr[i]){
            smallest = arr[i];
        }
    }

    cout<<"smallest Elemet is "<<smallest<<endl;
    return 0;
}