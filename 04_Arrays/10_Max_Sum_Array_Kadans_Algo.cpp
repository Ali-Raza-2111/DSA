#include <iostream>
#include <climits>
using namespace std;


void maxSubArraySum(int *arr,int n){
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int start = 0; start < n; start++)
    {
        currSum+=arr[start];
        maxSum = max(currSum,maxSum);
        if (currSum<0)
        {
            currSum = 0;
        }
        
    }
    cout<<"Maximum Sum is "<<maxSum<<endl;
}


int main(){
    int arr[6] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    maxSubArraySum(arr,n);
    return 0;
}