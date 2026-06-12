#include <iostream>
#include<climits>
using namespace std;

int main(){
    int size = 5;
    int arr[size] = {5,1,3,4,2};
    int first = INT_MIN,second = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if(arr[i]>first){
            first = second;
            first = arr[i];
        }
        if(arr[i]>second && arr[i]!=first){
            second = arr[i];
        }
    }

    cout<<"The second largest element is "<<second;
    
    return 0;
}