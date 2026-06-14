#include <iostream>
using namespace std;

int main(){

    int n = 5;
    int arr[n] = {1,5,2,3,4};

    // O(n^2)
    // Bubble Sort
    // for (int i = 0; i <n-1; i++)
    // {
    //     for (int j = 0; j < n-i-1; j++)
    //     {
    //         if (arr[j]>arr[j+1])
    //         {
    //             swap(arr[j],arr[j+1]);
    //         }
            
    //     }
        
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    




    // O(log n)
    // Binary Search


    // int arr[n] = {1,2,3,4,5};
    // int st = 0,end = n-1;
    // int target = 3;
    // while (st<=end)
    // {
    //     int mid = st +(end-st)/2;
    //     if (arr[mid]<target)
    //     {
    //         st = mid+1;
    //     }else if(arr[mid]>target){
    //         end = mid-1;
    //     }else{
    //         cout<<"The index is "<<mid;
    //         break;
    //     }
        
    // }



    //selection Sort O(n^2)

    int arr[n] = {1,5,2,3,4};
    for(int i = 0;i<n-1;i++){
        int midIndx = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j]<arr[midIndx])
            {
                midIndx = j;
            }
            
        }
        swap(arr[i],arr[midIndx]);
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }


    cout<<endl;
    return 0;
}