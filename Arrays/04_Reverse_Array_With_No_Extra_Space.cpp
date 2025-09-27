#include <iostream>
using namespace std;

void printArr(int *arr,int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
int main(){
    int arr[5]= {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    
    int copyArr[5];


    //For copying the orignal array to Copy Array
    for (int i = 0; i < size; i++)
    {
        int j = size - i - 1;
        copyArr[i] = arr[j];

    }

    //For copying the Copy Array to Orignal Array

    for (int i = 0; i < size; i++)
    {
        arr[i] = copyArr[i];        
    }

    printArr(arr,size);
    

    return 0;
}