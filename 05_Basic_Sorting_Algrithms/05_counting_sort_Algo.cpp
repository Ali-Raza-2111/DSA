#include <iostream>
#include <climits>
using namespace std;

void printArr(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void countSort(int arr[],int n){
    int freq[1000] = {0};
    int minVal = INT_MAX,maxVal = INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
        minVal = min(minVal,arr[i]);
        maxVal = max(maxVal,arr[i]);
    }

    for (int i = minVal,j=0; i <= maxVal; i++)
    {
        while (freq[i]>0)
        {
            arr[j++] = i;
            freq[i]--;
        }
        
    }
    
    printArr(arr,n);
}
int main() {
    int arr[5] = {5,4,3,1,2};
    int n = sizeof(arr)/sizeof(int);
    countSort(arr,n);
    return 0;
}
