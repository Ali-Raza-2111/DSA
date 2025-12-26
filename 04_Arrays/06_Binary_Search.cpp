#include <iostream>
using namespace std;

int binarySearch(int *arr,int n,int key){
    int start = 0,end = n-1;
    while (start<=end)
    {
        int mid = (start+end)/2;
        if (arr[mid] == key)
        {
            return mid;
        }else if (arr[mid]<key)
        {
            start = mid+1;
        }else{
            end = mid - 1;
        }
    }
    return -1;
    
}
int main(){
    int arr[10] = {1,2,3,4,15,65,78,9,54,66};
    int size = sizeof(arr)/sizeof(int);

    int index = binarySearch(arr,10,54);
    cout<<index<<endl;
    return 0;
}