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
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    
    int start = 0,end = size-1;

    while (start<end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    
    printArr(arr,size);
    return 0;
}