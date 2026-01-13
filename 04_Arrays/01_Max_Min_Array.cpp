#include <iostream>
using namespace std;

int main(){
    int arr[5] = {5,4,3,9,12};
    
    int max = arr[0];
    int min = arr[0];
    int length = sizeof(arr)/sizeof(int);


    for (int i = 0; i < length ; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
        if (arr[i]<min)
        {
            min = arr[i];
        }
        
    }

    cout<<"Maximum number\t"<<max<<endl;
    cout<<"Minimum number\t"<<min<<endl;
    
    
    return 0;
}