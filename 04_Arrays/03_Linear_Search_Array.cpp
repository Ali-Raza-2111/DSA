#include <iostream>
using namespace std;

int LinearSearch(int *arr,int n,int key){
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==key)
        {
            return i;
        }
        
    }
    return -1;
    
}

int main(){
    int arr[5] = {1,2,6,8,9};
    int length = sizeof(arr) / sizeof(int);

    int index = LinearSearch(arr,length,10);
    cout<<"Index Number is "<<index<<endl;
    return 0;
}